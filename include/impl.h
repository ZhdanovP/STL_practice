#pragma once
#include <sstream>
#include <iterator>
#include <numeric>
#include <forward_list>
#include <iostream>

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
    std::stringstream inputStream( input );
    std::forward_list<std::string> words;
    std::copy( std::istream_iterator<std::string>( inputStream ),
               std::istream_iterator<std::string>(),
               std::front_inserter( words ) );

    return std::accumulate( words.begin(), words.end(), std::string(""),
                        []( const std::string& a, const std::string& b )
                        {
                            return ( a.empty() ? b : a + " " + b );
                        });
}
