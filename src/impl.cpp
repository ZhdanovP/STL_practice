#include "impl.h"
#include <map>

int adaptNewGradesToGrandparents(int grade) {
    if (grade < 0 || grade > 100) return 0;
    std::map<int, int> adaptMap {
        { 101, 5 },
        { 90, 4 },
        { 70, 3 },
        { 50, 2 },
        { 30, 1 }
    };
    auto it = adaptMap.upper_bound(grade);
    return it->second;
}
