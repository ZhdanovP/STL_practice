#include "impl.h"
#include <set>
#include <algorithm>
#include <iterator>

bool is_anagram(const std::string& first, const std::string& second)
{
   std::set<char> set_first;
   std::for_each(first.begin(), first.end(), [&set_first](const char & ch)
      {
         set_first.insert(ch);
      });

   std::set<char> set_second;
   std::for_each(second.begin(), second.end(), [&set_second](const char& ch)
      {
         set_second.insert(ch);
      });

   return set_first == set_second && first.size() == second.size();
}
