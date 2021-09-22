#include "impl.h"
#include <unordered_map>

bool is_anagram( const std::string& first, const std::string& second )
{
   if ( first.size() != second.size() )
   {
      return false;
   }

   std::unordered_map<char, int> lettersCounter;

   for ( size_t i = 0; i < first.size(); ++i )
   {
      ++lettersCounter[first[i]];
      --lettersCounter[second[i]];
   }

   for ( const auto& [letter, count] : lettersCounter )
   {
      if ( count != 0 )
      {
         return false;
      }
   }

   return true;
}
