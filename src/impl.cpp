#include "impl.h"

std::string reverseWords(const std::string& input)
{
    if (input.empty()) {
        return std::string();
    }

    std::stringstream stream(input);
    std::deque<std::string> words;
    while (stream) {
        std::string word;
        stream >> word;
        if (!word.empty()) {
            words.push_back(word);
        }
    }
    if (words.empty()) {
        return std::string();
    }

    std::string reversed = words.back();
    words.pop_back();

    std::for_each(words.begin(), words.end(), [&reversed](const std::string &eachWord){
        reversed.push_back(' ');
        std::copy(eachWord.begin(), eachWord.end(), std::back_inserter(reversed));

    });
}
