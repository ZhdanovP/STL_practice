#pragma once
#include <string>
#include <map>
#include <iostream>

/**
 You must implement a conversion from 100-point grade system to 5-point system.

 Example: 0-29 – 1;  30-49 – 2;
        50-69 – 3; 70-89 – 4;
        90+ - 5;
 */
static std::map<uint16_t, uint16_t> scores {{29, 1}, {49, 2}, {69, 3}, {89, 4}, {100, 5}};

uint16_t convertGrade(uint16_t score){
    if(score > 100){
        score = 100;
    }
    return scores.lower_bound(score)->second;
}
