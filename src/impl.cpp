#include "impl.h"
#include "xxhash.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

// use this for hashing
auto xx_hash = []( const std::string& file ) {
   std::ifstream stream{ file };

   if ( !stream )
   {
      std::cerr << "File " << file << " can't be opened" << std::endl;
      return xxh::hash_t<64>{};
   }

   const auto length = fs::file_size( file );
   std::vector<char> buffer( length );
   stream.read( buffer.data(), length );

   return xxh::xxhash<64>( buffer );
};

/** @todo Implement filtering files by different buckets by specified criteria*/
template <class FilterCriteria>
filtering_map filter( const std::vector<std::string>& files, FilterCriteria criteria )
{
   filtering_map fileGroups;
   for ( const auto& file : files )
   {
      // criteria returns key - id of the group for specified file
      // so below line means: get group for that file and add this this file to it's group
      fileGroups[criteria( file )].push_back( file );
   }

   return fileGroups;
}

/** @todo Implement function that will remove group in if it has only one or zero elements */
void removeUniqueGroups( filtering_map& filteredData )
{
   for ( auto it = filteredData.begin(); it != filteredData.end(); )
   {
      const size_t groupSize{ it->second.size() };
      if ( groupSize < 2 )
      {
         it = filteredData.erase( it );
      }
      else
      {
         ++it;
      }
   }
}

/** @note HELPER */
template <class FilterCriteria>
filtering_map groupDuplicates( const std::vector<std::string>& dataSource, FilterCriteria criteria )
{
   filtering_map grouped = filter( dataSource, criteria );
   removeUniqueGroups( grouped );
   return grouped;
}

/** @todo With help of std filesystem, lists all regular files under specified directory
 * recursively*/
std::vector<std::string> listFiles( const std::string& directory )
{
   if ( !fs::is_directory( directory ) )
   {
      throw fs::filesystem_error( std::string( "Provided path is not directory: " + directory ),
                                  std::error_code{} );
   }

   std::vector<std::string> files;

   // [Question]
   // this will not work, since *files* is vector of strings, not directory_entries
   // can code be modified somehow to use copy_if instead of loop?
   // std::copy_if( fs::recursive_directory_iterator( directory ), {}, std::back_inserter( files ),
   //               []( const fs::directory_entry& entry ) { return entry.is_regular_file(); } );

   for ( const auto& directoryEntry : fs::recursive_directory_iterator( directory ) )
   {
      if ( directoryEntry.is_regular_file() )
      {
         files.push_back( directoryEntry.path() );
      }
   }

   return files;
}

/** @todo Implement function that will transform map to a vector */
std::vector<std::string> flattenGrouped( const filtering_map& grouped )
{
   std::vector<std::string> flat;

   for ( const auto& [key, strings] : grouped )
   {
      flat.insert( flat.end(), strings.begin(), strings.end() );
   }

   return flat;
}

/**
 * @todo Implement function that fill find duplicated files under the directory recursively
 * @param rootPath - directory to check
 * @return list of duplicated files, grouped by content
 */
std::vector<std::vector<std::string>> findDuplicates( const std::string& rootPath )
{
   // filter by size
   filtering_map filteredGroups{ groupDuplicates(
       listFiles( rootPath ), []( const std::string& str ) { return fs::file_size( str ); } ) };

   // filter by content
   filteredGroups =
       std::move( groupDuplicates( flattenGrouped( filteredGroups ),
                                   []( const std::string& str ) { return xx_hash( str ); } ) );

   // flatten
   std::vector<std::vector<std::string>> result;
   for ( auto& [criteria, group] : filteredGroups )
   {
      result.push_back( std::move( group ) );
   }

   return result;
}
