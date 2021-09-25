#include "impl.h"
#include <bitset>

static days getIntersection( const calendar& first, const calendar& second )
{
   std::bitset<daysInMonth> left( first, 0, std::string::npos, availableMarker, vacationMarker );
   std::bitset<daysInMonth> right( second, 0, std::string::npos, availableMarker, vacationMarker );

   const auto intersect = left & right;

   return intersect.count();
}

std::tuple<worker_id, worker_id, days>
getMaxIntersection( const std::unordered_map<worker_id, calendar>& workerVacations )
{
   days maxIntersection{ 0 };
   worker_id worker1, worker2;

   for ( auto i = workerVacations.begin(); i != workerVacations.end(); ++i )
   {
      for ( auto j = std::next( i ); j != workerVacations.end(); ++j )
      {
         const days intersection = getIntersection( i->second, j->second );
         if ( intersection > maxIntersection )
         {
            maxIntersection = intersection;
            worker1         = i->first;
            worker2         = j->first;
         }
      }
   }

   return std::tie( worker1, worker2, maxIntersection );
}
