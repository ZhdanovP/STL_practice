#include "impl.h"
#include <vector>
#include <stack>
#include <algorithm>

const std::vector<std::pair<char, char>> brackets {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
    {'<', '>'}
};

bool isValid(const std::string& source)
{
    if(source.empty()){
        return true;
    }

    auto isOpened = [](const char c){
        return std::find_if(brackets.begin(), brackets.end(), [c](const std::pair<char, char>& p){
            return p.first == c;
        }) != brackets.end();
    };

    auto isClosed = [](const char c){
        return std::find_if(brackets.begin(), brackets.end(), [c](const std::pair<char, char>& p){
            return p.second == c;
        }) != brackets.end();
    };

    auto isPair = [](const char first, const char second){
        return std::find_if(brackets.begin(), brackets.end(), [=](const std::pair<char, char>& p){
            return p.first == first && p.second == second;
        }) != brackets.end();
    };

    std::stack<char> container;

    for(const auto c : source){
        if(isOpened(c)){
            container.push(c);
        }

        auto isClosed_ = isClosed(c);
        if(isClosed_ && container.empty()){
            return false;
        } else if(isClosed_ && isPair(container.top(), c)){
            container.pop();
        }
    }
    return container.empty();
}
