#pragma once
#include <sstream>
#include <deque>
#include <iterator>
#include <algorithm>

/**
 * @todo Implement function that will reverse words in a sentence
 * @example "Hello there" -> "there Hello"
 * @param input - sentence with words splitted by spaces
 * @return Sentence with reversed order of words
 *
 * @warning YOU MUST USE STRING STREAMS AND STREAM ITERATORS!
 */
std::string reverseWords(const std::string& input) 
{
    if (input.empty()) 
    {
        return "";
    }

    std::istringstream inStream( input );
    std::deque<std::string> words( std::istream_iterator<std::string>( inStream ), {} );

    std::ostringstream outStream;
    std::copy( words.rbegin(), std::prev(words.rend()), std::ostream_iterator<std::string>( outStream, " " ) );
    outStream << *words.begin();

    return outStream.str();
}
