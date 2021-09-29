#include "impl.h"
#include <experimental/filesystem>
#include <fstream>
#include <numeric>
#include "xxhash.h"
#include <iostream>
#include <algorithm>

namespace fs = std::experimental::filesystem;

// use this for hashing
auto xx_hash = [] (const std::string &file)
{
    std::ifstream stream {file};

    if (!stream)
    {
        std::cerr << "File " << file << " can't be opened" << std::endl;
        return xxh::hash_t<64> {};
    }

    const auto length = fs::file_size(file);
    std::vector<char> buffer(length);
    stream.read(buffer.data(), length);

    return xxh::xxhash<64>(buffer);
};

class IndexFilter
{
public:
    IndexFilter() = default;
    size_t operator()(const std::string &file)
    {
        const auto hash = xx_hash(file);
        auto it = std::find(uniqueHashes.begin(), uniqueHashes.end(), hash);
        if (it == uniqueHashes.end()) {
            if (uniqueHashes.size() == uniqueHashes.max_size()) {
                throw std::out_of_range("Max size is exceeded");
            }
            uniqueHashes.push_back(hash);
            return uniqueHashes.size() - 1;
        }
        return std::distance(uniqueHashes.begin(), it);
    }
private:
    std::vector<unsigned long> uniqueHashes;
};

std::vector<std::string> listFiles(const std::string& directory)
{
    std::vector<std::string> list;
    for (const auto & entry : fs::recursive_directory_iterator(directory)) {
        if (fs::is_regular_file(entry.status())) {
            list.push_back(entry.path());
        }
    }
    return list;
}

/** @todo Implement filtering files by different buckets by specified criteria*/
template<class FilterCriteria>
filtering_map filter(const std::vector<std::string>& files, FilterCriteria filter)
{
    filtering_map data;
    for (const auto & file : files) {
        const auto index = filter(file);
        data[index].push_back(file);
    }
    return data;
}

void removeUniqueGroups(filtering_map& filteredData)
{
    for (auto it = filteredData.begin(); it != filteredData.end(); ) {
        if (it ->second.size() < 2) {
            it = filteredData.erase(it);
        } else {
            ++it;
        }
    }
}

/** @note HELPER */
template<class Filter>
filtering_map groupDuplicates (const std::vector<std::string>& dataSource, Filter filterCriteria)
{
    auto grouped = filter(dataSource, filterCriteria);
    removeUniqueGroups(grouped);
    return grouped;
}

std::vector<std::vector<std::string> > flattenGrouped (const filtering_map& grouped)
{
    std::vector<std::vector<std::string>> flatten;
    for (const auto & group : grouped) {
        flatten.push_back(group.second);
    }
    return flatten;
}

std::vector<std::vector<std::string> > findDuplicates(const std::string &rootPath)
{
    const auto list = listFiles(rootPath);
    const auto filtering = groupDuplicates(list, IndexFilter{});
    return flattenGrouped(filtering);
}
