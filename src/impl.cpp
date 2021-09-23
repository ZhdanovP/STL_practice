#include "impl.h"
#include <vector>
#include <stack>
#include <algorithm>

const std::vector<std::pair<char, char>> brackets {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};

bool isValid(const std::string& source)
{
    std::stack<std::string::value_type> bracketsInText;
    for (const auto& ch : source) {
        auto it = std::find_if(brackets.begin(), brackets.end(), [&ch](const std::pair<char, char> &pair) {
            return ch == pair.first || ch == pair.second;
        });
        if (it == brackets.end()) {
            continue; // skip
        }

        if (ch == it->first) {
            bracketsInText.push(ch);
        } else { // ch == it->second
            if (it->first == bracketsInText.top()) {
                bracketsInText.pop();
            } else {
                break;
            }
        }
    }

    return bracketsInText.empty();
}
