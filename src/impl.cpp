#include "impl.h"
#include <bitset>

std::tuple<worker_id, worker_id, days> getMaxIntersection(const std::unordered_map<worker_id, calendar>& workerVacations)
{
    std::tuple<worker_id, worker_id, days> maxIntersection {0, 0, 0};
    for (auto it_i = workerVacations.begin(); it_i != workerVacations.end(); ++it_i) {
        const std::bitset<daysInMonth> workerCalendar_i {it_i->second, 0, std::string::npos, availableMarker /*zero*/, vacationMarker /*one*/};

        for (auto it_j = std::next(it_i); it_j != workerVacations.end(); ++it_j) {
            const std::bitset<daysInMonth> workerCalendar_j {it_j->second, 0, std::string::npos, availableMarker /*zero*/, vacationMarker /*one*/};
            const auto intersection = workerCalendar_i & workerCalendar_j;
            const auto vacationIntersectionNumber = intersection.count();
            if (vacationIntersectionNumber > std::get<2>(maxIntersection)) {
                maxIntersection = std::make_tuple(it_i->first, it_j->first, vacationIntersectionNumber);
            }
        }
    }
    return maxIntersection;
}
