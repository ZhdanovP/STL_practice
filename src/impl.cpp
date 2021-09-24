#include "impl.h"
#include <unordered_map>

bool is_anagram(const std::string& first, const std::string& second)
{
    std::unordered_map<char, unsigned int> original;
    for (const auto &ch : second) {
        auto it = original.find(ch);
        if (it == original.end()) {
            original[ch] = 1;
        } else {
            ++(it->second);
        }
    }

    for (const auto &ch : first) {
        auto it = original.find(ch);
        if (it == original.end()) {
            return false;
        }
        if (it->second == 1) {
            original.erase(it);
            continue;
        }
        --(it->second);
    }

    return original.empty();
}
