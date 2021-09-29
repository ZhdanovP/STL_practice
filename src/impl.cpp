#include "impl.h"
#include <bitset>

static days getVacationIntersection(const calendar& firstVacation, const calendar& secondVacation)
{
    const std::bitset<daysInMonth> firstVacationBitset(firstVacation, 0, std::string::npos,
        availableMarker, vacationMarker);
    const std::bitset<daysInMonth> secondVacationBitset(secondVacation, 0, std::string::npos,
        availableMarker, vacationMarker);
    return (firstVacationBitset & secondVacationBitset).count();
}

std::tuple<worker_id, worker_id, days>
    getMaxIntersection(const std::unordered_map<worker_id, calendar>& workerVacations)
{
    worker_id firstWorker = 0;
    worker_id secondWorker = 0;
    days maxIntersection = 0;
    for (auto firstIt = workerVacations.begin(); firstIt != workerVacations.end(); ++firstIt)
    {
        for (auto secondIt = std::next(firstIt); secondIt != workerVacations.end(); ++secondIt)
        {
            days intersection = getVacationIntersection(firstIt->second, secondIt->second);
            if (intersection > maxIntersection)
            {
                maxIntersection = intersection;
                firstWorker = firstIt->first;
                secondWorker = secondIt->first;
            }
        }
    }
    return std::tie(firstWorker, secondWorker, maxIntersection);
}
