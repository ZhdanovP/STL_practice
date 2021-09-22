#include "impl.h"
#include <cstdint> // uint8_t
#include <map>

/*
 * Table for convertion: 100 point -> 5 point
 * 100 point grades values set as upper range values for each grade range:
 * [0;29], [30;49], [50;69], [70;89], [90;MAX]
 *   1        2        3        4        5
 */
static const std::map<uint8_t, uint8_t> tableBounds100to5{
    { 29, 1 }, { 49, 2 }, { 69, 3 }, { 89, 4 }, { 255, 5 } };

uint8_t convertTo5PointGrade( uint8_t grade100Point )
{
   return ( *tableBounds100to5.lower_bound( grade100Point ) ).second;
}
