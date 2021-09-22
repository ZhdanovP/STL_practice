#pragma once
#include <string>

/**
 You must implement a conversion from 100-point grade system to 5-point system.

 Example: 0-29 – 1;  30-49 – 2;
        50-69 – 3; 70-89 – 4;
        90+ - 5;
 */

/** @param mark - mark by 100-point grade system
 *  @return pair of flag "success" and mark by 5-point system
 */
std::pair<bool, unsigned int> convert(const unsigned int &mark);
