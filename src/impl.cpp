#include "impl.h"
#include <algorithm>

std::string reverseWords(const std::string& input)
{
    if (input.empty()) return "";
    std::deque<std::string> words;
    std::stringstream inputStream(input);
    std::copy(std::istream_iterator<std::string>(inputStream),
        std::istream_iterator<std::string>(),
        std::back_inserter(words));
    if (words.empty()) return "";
    std::stringstream outputStream;
    std::copy(words.rbegin(), std::prev(words.rend()),
        std::ostream_iterator<std::string>(outputStream, " "));
    outputStream << *words.begin();
    return outputStream.str();
}
