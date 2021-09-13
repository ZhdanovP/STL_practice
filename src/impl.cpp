#include "impl.h"

void DataBrowser::userLeave(const std::string &userId)
{
    m_dataReaders.erase(userId);
}

bool DataBrowser::getDataType1(const std::string &userId, std::vector<size_t> &returnValues) const
{
    auto safeCallLambda = [this, &returnValues](const std::unique_ptr<IDataSelector>& selector)
    {
        auto invokeLambda = [](const IDataSelector* selector, std::vector<size_t>& values)
        {
            return selector->getDataType1(values, 0);
        };
        return invokeDataRequest(invokeLambda, selector, returnValues);
    };
    return safeCall(userId, safeCallLambda);
}

bool DataBrowser::getDataType2(std::vector<size_t> &returnValues, const std::string &userId) const
{
    auto funcGetDataType2 = std::mem_fn(&IDataSelector::getDataType2);
    auto safeCallLambda = [this, &returnValues, funcGetDataType2](const std::unique_ptr<IDataSelector>& selector)
    {
        return invokeDataRequest(funcGetDataType2, selector, returnValues);
    };
    return safeCall(userId, safeCallLambda);
}

bool DataBrowser::getDataType3(const std::string &userId, std::vector<std::string> &returnValues) const
{
    auto safeCallLambda = [this, &returnValues](const std::unique_ptr<IDataSelector>& selector)
    {
        auto funcGetDataType3 = std::mem_fn( &IDataSelector::getDataType3 );
        std::deque<size_t> unprocessedResults {};
        bool success = invokeDataRequest(funcGetDataType3, selector, unprocessedResults);
        returnValues = process(unprocessedResults);
        return success;
    };
    return safeCall(userId, safeCallLambda);
}

template<class T>
std::vector<std::string> DataBrowser::process(const T& source) const
{
    std::vector<std::string> results;
    std::transform(source.begin(), source.end(), std::back_inserter(results),
                   [](const size_t& value) { return std::to_string(value); });
    return results;
}
