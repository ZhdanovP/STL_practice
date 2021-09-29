#include "impl.h"
#include <bitset>


std::tuple<worker_id, worker_id, days> getMaxIntersection(const std::unordered_map<worker_id, calendar>& workerVacations)
{
    std::tuple<worker_id, worker_id, days> maxIntersection {0, 0, 0};
    for (auto it_i = workerVacations.begin(); it_i != workerVacations.end(); ++it_i) {
        std::bitset<daysInMonth> workerCalendar_i {it_i->second, 0, std::string::npos, availableMarker /*zero*/, vacationMarker /*one*/};

        for (auto it_j = it_i; it_j != workerVacations.end(); ++it_j) {
            if (it_i->first == it_j->first) {
                continue;
            }
            std::bitset<daysInMonth> workerCalendar_j {it_j->second, 0, std::string::npos, availableMarker /*zero*/, vacationMarker /*one*/};
            auto intersection = workerCalendar_i & workerCalendar_j;
            const auto vacationIntersection = intersection.count();
            if (vacationIntersection > std::get<2>(maxIntersection)) {
                maxIntersection = std::make_tuple(it_i->first, it_j->first, vacationIntersection);
            }
        }
    }
    return maxIntersection;
}
