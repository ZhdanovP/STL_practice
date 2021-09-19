#pragma once
#include <algorithm>
#include <deque>
#include <iterator>
#include <sstream>

/**
 * @todo Implement function that will reverse words in a sentence
 * @example "Hello there" -> "there Hello"
 * @param input - sentence with words splitted by spaces
 * @return Sentence with reversed order of words
 *
 * @warning YOU MUST USE STRING STREAMS AND STREAM ITERATORS!
 */
std::string reverseWords( const std::string& input )
{
   std::istringstream inputStream( input );

   // https://www.py4u.net/discuss/71357
   std::deque<std::string> words( std::istream_iterator<std::string>( inputStream ), {} );

   std::ostringstream outStream;
   std::copy( words.rbegin(), words.rend(), std::ostream_iterator<std::string>( outStream, " " ) );

   std::string result( outStream.str() );
   if ( !result.empty() )
   {
      result.pop_back(); // remove trailing space
   }

   return result;
}
