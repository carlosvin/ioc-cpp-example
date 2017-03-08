#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "src/iocTest/cpp/catch.hpp"
#include "src/ioc/cpp/FilesFinder.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <exception>

TEST_CASE( "List build dir files", "[files]" ) 
{
    auto files = getDirectoryFiles("."); 
    std::cout << files.size() << " files in the dir ." << std::endl;
    std::stringstream  s;

    std::copy(
        files.begin(), files.end(), 
        std::ostream_iterator<std::string>(s, ","));
    std::cout <<  s.str()  << std::endl;

    std::for_each(files.begin(), files.end(), [](const std::string& n) { std::cout << n << std::endl; });
    //INFO(files);
    REQUIRE_FALSE( files.empty() );
    REQUIRE( std::find(files.begin(), files.end(), "build.ninja") != files.end() );
    REQUIRE_THROWS_AS( getDirectoryFiles("nonexistentdir"), std::system_error );
}
