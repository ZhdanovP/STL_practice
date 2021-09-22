#include "impl.h"
#include <cstdint> // uint8_t
#include <map>

static const std::map<uint8_t, uint8_t> gradesFrom100to5{
    { 29, 1 }, { 49, 2 }, { 69, 3 }, { 89, 4 }, { 255, 5 } };

uint8_t convertTo5PointGrade( uint8_t grade100Point )
{
   return ( *gradesFrom100to5.lower_bound( grade100Point ) ).second;
}
