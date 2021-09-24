#include "impl.h"
#include <set>
#include <vector>
#include <algorithm>

/**
 You must implement a conversion from 100-point grade system to 5-point system.

 Example: 0-29 – 1;  30-49 – 2;
        50-69 – 3; 70-89 – 4;
        90+ - 5;
 */

const std::set<std::string>    rules    = { "29", "49",  "69",  "89", "99" };
const std::vector<std::string> marks    = { "1", "2", "3", "4", "5" };

std::string Convertor(const std::string& str)
{
   const std::size_t in_size = str.length();
   const bool size_valid = (in_size <= 2);
   std::string result = size_valid ? "0" : "5";
   if (size_valid)
   {
      const std::string local_str = in_size == 2 ? str : ("0" + str);
      auto it_first = std::lower_bound(rules.begin(), rules.end(), local_str);
      if (it_first != rules.end())
      {
         auto mark_index = std::distance(rules.begin(), it_first);
         if (mark_index < marks.size())
         {
            result = marks[mark_index];
         }
      }
   }
   return result;
}
