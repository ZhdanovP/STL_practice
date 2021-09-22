#pragma once
#include <sstream>
#include <deque>
#include <iterator>
#include <stack>
#include <iostream>
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
   std::istringstream iss(input);
   std::deque<std::string> deque;
   while (!iss.eof())
   {
      std::string word;
      iss >> word;
      if (!word.empty())
      {
         deque.emplace_back(word);
      }
   }

   std::ostringstream oss;
   std::for_each(deque.rbegin(), deque.rend(), [&oss](const std::string & str)
      {
         if (!oss.str().empty())
         {
            oss << " ";
         }
         oss << str;
      });

   return oss.str();
}
