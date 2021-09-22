#include "impl.h"
#include <cstdint> // uint8_t
#include <map>

static const std::map<std::pair<uint8_t, uint8_t>, uint8_t> gradesFrom100to5{
    { { 0, 29 }, 1 }, { { 30, 49 }, 2 }, { { 50, 69 }, 3 }, { { 70, 89 }, 4 }, { { 90, 100 }, 5 } };

uint8_t convertTo5PointGrade( uint8_t grade100Point )
{
   for ( const auto& [range, grade5Point] : gradesFrom100to5 )
   {
      if ( range.first <= grade100Point && grade100Point <= range.second )
      {
         return grade5Point;
      }
   }

   return ( *gradesFrom100to5.rbegin() ).second;
}
