#pragma once
#include <string>
#include <vector>
#include <algorithm>
/**
 You must implement a conversion from 100-point grade system to 5-point system.

 Example: 0-29 – 1;  30-49 – 2;
        50-69 – 3; 70-89 – 4;
        90+ - 5;
 */

 const std::vector<int> gradeSystem = {29, 49, 69, 89, 100};


int convert100pointTo5(int points)
{
    if (points < 1 || points > 100)
    {
        return 0;
    }

    auto upper = std::lower_bound(gradeSystem.begin(), gradeSystem.end(), points);
    return (std::distance(gradeSystem.begin(), upper)+1);
}