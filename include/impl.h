#pragma once
#include <cstdint> // uint8_t

/**
 You must implement a conversion from 100-point grade system to 5-point system.

 Example:
       0-29 – 1;
       30-49 – 2;
       50-69 – 3;
       70-89 – 4;
       90+ - 5;
 */
uint8_t convertTo5PointGrade( uint8_t grade100Point );
