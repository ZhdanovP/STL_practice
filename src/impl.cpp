#include "impl.h"

void DataBrowser::userLeave( const std::string &userId )
{
   m_dataReaders.erase( userId );
}

bool DataBrowser::getDataType1( const std::string &userId, std::vector<size_t> &returnValues ) const
{
   auto getDataType1Adapter = []( const IDataSelector *selector,
                                  std::vector<size_t> &returnValues ) {
      return selector->getDataType1( returnValues, 0 );
   };

   auto invokeDataRequestAdapter = [this, &getDataType1Adapter, &returnValues](
                                       const std::unique_ptr<IDataSelector> &selector ) {
      return invokeDataRequest( getDataType1Adapter, selector, returnValues );
   };

   return safeCall( userId, invokeDataRequestAdapter );
}

bool DataBrowser::getDataType2( std::vector<size_t> &returnValues, const std::string &userId ) const
{
   auto getDataType2Adapter = []( const IDataSelector *selector,
                                  std::vector<size_t> &returnValues ) {
      return selector->getDataType2( returnValues );
   };

   auto invokeDataRequestAdapter = [this, &getDataType2Adapter, &returnValues](
                                       const std::unique_ptr<IDataSelector> &selector ) {
      return invokeDataRequest( getDataType2Adapter, selector, returnValues );
   };

   return safeCall( userId, invokeDataRequestAdapter );
}

bool DataBrowser::getDataType3( const std::string &userId,
                                std::vector<std::string> &returnValues ) const
{
   auto getDataType3Adapter = [this]( const IDataSelector *selector,
                                      std::vector<std::string> &returnValues ) {
      std::deque<size_t> unprocessedResults{};
      bool success{ selector->getDataType3( unprocessedResults ) };
      returnValues = process( unprocessedResults );
      return success;
   };

   auto invokeDataRequestAdapter = [this, &getDataType3Adapter, &returnValues](
                                       const std::unique_ptr<IDataSelector> &selector ) {
      return invokeDataRequest( getDataType3Adapter, selector, returnValues );
   };

   return safeCall( userId, invokeDataRequestAdapter );
}

bool DataBrowser::safeCall( const std::string &userId,
                            std::function<bool( const std::unique_ptr<IDataSelector> & )> f ) const
{
   // find reader
   const auto &dataReader_it{ m_dataReaders.find( userId ) };
   if ( dataReader_it == m_dataReaders.end() )
   {
      return false;
   }

   // check for errors
   if ( !dataReader_it->second )
   {
      return false;
   }

   // call functor
   return f( dataReader_it->second );
}

template <class T>
std::vector<std::string> DataBrowser::process( const T &source ) const
{
   std::vector<std::string> results;
   std::transform( source.begin(), source.end(), std::back_inserter( results ),
                   []( const size_t &value ) { return std::to_string( value ); } );
   return results;
}
