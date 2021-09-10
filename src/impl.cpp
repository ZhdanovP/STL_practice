#include "impl.h"

void DataBrowser::userLeave(const std::string &userId)
{
    m_dataReaders.erase(userId);
}

bool DataBrowser::getDataType1(const std::string &userId, std::vector<size_t> &returnValues) const
{
    auto lambdaDataType1 = [](const IDataSelector *selector, std::vector<size_t> &returnValues) {
        return selector->getDataType1(returnValues, 0);
    };

    auto lambdaDataRequest = [this, &returnValues, &lambdaDataType1](const std::unique_ptr<IDataSelector> &selector) {
        return invokeDataRequest(lambdaDataType1, selector, returnValues);
    };

    return safeCall(userId, lambdaDataRequest);
}

bool DataBrowser::getDataType2(std::vector<size_t> &returnValues, const std::string &userId) const
{
    auto lambdaDataType2 = [](const IDataSelector *selector, std::vector<size_t> &returnValues) {
        return selector->getDataType2(returnValues);
    };

    auto lambdaDataRequest = [this, &returnValues, &lambdaDataType2](const std::unique_ptr<IDataSelector> &selector) {
        return invokeDataRequest(lambdaDataType2, selector, returnValues);
    };

    return safeCall(userId, lambdaDataRequest);
}

bool DataBrowser::getDataType3(const std::string &userId, std::vector<std::string> &returnValues) const
{
    auto lambdaDataType3 = [this](const IDataSelector *selector, std::vector<std::string> &returnValues) {
        std::deque<size_t> unprocessedResults {};
        const bool success = selector->getDataType3(unprocessedResults);
        returnValues = process(unprocessedResults);
        return success;
    };

    auto lambdaDataRequest = [this, &returnValues, &lambdaDataType3](const std::unique_ptr<IDataSelector> &selector) {
        return invokeDataRequest(lambdaDataType3, selector, returnValues);
    };

    return safeCall(userId, lambdaDataRequest);
}

template<class T>
std::vector<std::string> DataBrowser::process(const T& source) const
{
    std::vector<std::string> results;
    std::transform(source.begin(), source.end(), std::back_inserter(results),
                   [](const size_t& value) { return std::to_string(value); });
    return results;
}
