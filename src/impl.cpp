#include "impl.h"
#include <vector>
#include <stack>

const std::vector<std::pair<char, char>> brackets {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};

bool isOpenBrace(char c) {
    for (auto bracesPair : brackets) {
        if (bracesPair.first == c) return true;
    }
    return false;
}

bool isCloseBrace(char c) {
    for (auto bracesPair : brackets) {
        if (bracesPair.second == c) return true;
    }
    return false;
}

bool isValidPair(char first, char second) {
    for (auto bracesPair : brackets) {
        if (bracesPair.first == first && bracesPair.second == second)
            return true;
    }
    return false;
}

bool isValid(const std::string& source) {
    std::stack<char> braces {};
    for (auto it = source.cbegin(); it != source.cend(); ++it) {
        if (isOpenBrace(*it)) {
            braces.push(*it);
        }
        else if (isCloseBrace(*it)) {
            if (braces.empty() || !isValidPair(braces.top(), *it)) return false;
            braces.pop();
        }
    }
    if (braces.empty()) return true;
    else return false;
}
