#include "impl.h"
#include <unordered_map>

std::unordered_map<char, unsigned int> createIdentifier(const std::string& word)
{
    std::unordered_map<char, unsigned int> identifier;
    for (const auto &ch : word) {
        auto it = identifier.find(ch);
        if (it == identifier.end()) {
            identifier[ch] = 1;
        } else {
            ++(it->second);
        }
    }
    return identifier;
}

bool is_anagram(const std::string& first, const std::string& second)
{
    const std::unordered_map<char, unsigned int> original = createIdentifier(second);
    const std::unordered_map<char, unsigned int> anagram = createIdentifier(first);
    if (original.empty() || anagram.empty()) {
        return false;
    }

    return original == anagram;
}
