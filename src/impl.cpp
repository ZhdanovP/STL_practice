#include "impl.h"
#include <unordered_map>

bool is_anagram(const std::string& first, const std::string& second)
{
    if (first.size() != second.size()) return false;
    std::unordered_map<char, int> symbolCounters;
    size_t size = first.size();
    for (size_t i = 0; i < size; ++i)
    {
        if (symbolCounters.find(first[i]) == symbolCounters.end())
        {
            symbolCounters[first[i]] = 1;
        }
        else
        {
            ++symbolCounters[first[i]];
        }
        if (symbolCounters.find(second[i]) == symbolCounters.end())
        {
            symbolCounters[second[i]] = -1;
        }
        else
        {
            --symbolCounters[second[i]];
        }
    }
    for (auto it = symbolCounters.cbegin(); it != symbolCounters.cend(); ++it)
    {
        if (it->second != 0) return false;
    }
    return true;
}
