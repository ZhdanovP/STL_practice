#include "impl.h"
#include <iterator>

void DataBrowser::userLeave(const std::string &userId)
{
    m_dataReaders.erase(userId);
}

bool DataBrowser::getDataType1(const std::string &userId, std::vector<size_t> &returnValues) const
{
   auto memFnDataType1Adapter = [](const IDataSelector* selector,
      std::vector<size_t>& returnValues)
   {
      return selector != nullptr && selector->getDataType1(returnValues, 0u);
   };
   //auto memFnDataType1 = std::mem_fn(&IDataSelector::getDataType2);
   //auto bind = std::bind(memFnDataType1, std::placeholders::_1/*, 0*/);

   auto functor = [this, memFnDataType1Adapter/*bind*/, &returnValues](const std::unique_ptr<IDataSelector>& ptr)
   {
      return invokeDataRequest(memFnDataType1Adapter/*bind*/, ptr, returnValues);
   };
   
   return safeCall(userId, functor);   
}

bool DataBrowser::getDataType2(std::vector<size_t> &returnValues, const std::string &userId) const
{
   auto memFnDataType1 = std::mem_fn(&IDataSelector::getDataType2);

   auto functor = [this, memFnDataType1, &returnValues](const std::unique_ptr<IDataSelector>& ptr)
   {
      return invokeDataRequest(memFnDataType1, ptr, returnValues);
   };

   return safeCall(userId, functor);
}

bool DataBrowser::getDataType3(const std::string &userId, std::vector<std::string> &returnValues) const
{
    std::deque<size_t> unprocessedResults {};
    auto memFnDataType1 = std::mem_fn(&IDataSelector::getDataType3);

    auto functor = [this, memFnDataType1, &unprocessedResults](const std::unique_ptr<IDataSelector>& ptr)
    {
       return invokeDataRequest(memFnDataType1, ptr, unprocessedResults);
    };
    
    const bool result = safeCall(userId, functor);
    if (result)
    {
       returnValues = process(unprocessedResults);
    }

    return result;
}

template<class T>
std::vector<std::string> DataBrowser::process(const T& source) const
{
    std::vector<std::string> results;
    std::transform(source.begin(), source.end(), std::back_inserter(results),
                   [](const size_t& value) { return std::to_string(value); });
    return results;
}
