#include "impl.h"

void DataBrowser::userLeave(const std::string &userId)
{
    m_dataReaders.erase(userId);
}

bool DataBrowser::getDataType1(const std::string &userId, std::vector<size_t> &returnValues) const
{
    auto safeCallback = [this, &returnValues](const std::unique_ptr<IDataSelector>& selector) {
        auto invokeCallback = [](const IDataSelector* selector, std::vector<size_t>& data) {
            return selector->getDataType1(data, 0);
        };
        return invokeDataRequest(invokeCallback, selector, returnValues);
    };
    return safeCall(userId, safeCallback);
}

bool DataBrowser::getDataType2(std::vector<size_t> &returnValues, const std::string &userId) const
{
    auto safeCallback = [this, &returnValues](const std::unique_ptr<IDataSelector>& selector) {
        auto invokeCallback = std::mem_fn(&IDataSelector::getDataType2);
        return invokeDataRequest(invokeCallback, selector, returnValues);
    };
    return safeCall(userId, safeCallback);
}

bool DataBrowser::getDataType3(const std::string &userId, std::vector<std::string> &returnValues) const
{
    auto safeCallback = [this, &returnValues](const std::unique_ptr<IDataSelector>& selector) {
        auto invokeCallback = [this, &returnValues](
            const IDataSelector* selector, std::vector<std::string>& data) {

            std::deque<size_t> unprocessedResults {};
            bool success = selector->getDataType3(unprocessedResults);
            returnValues = process(unprocessedResults);
            return success;
        };
        return invokeDataRequest(invokeCallback, selector, returnValues);
    };
    return safeCall(userId, safeCallback);
}

template<class T>
std::vector<std::string> DataBrowser::process(const T& source) const
{
    std::vector<std::string> results;
    std::transform(source.begin(), source.end(), std::back_inserter(results),
                   [](const size_t& value) { return std::to_string(value); });
    return results;
}
