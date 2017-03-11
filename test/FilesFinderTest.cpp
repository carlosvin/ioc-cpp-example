#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "src/FilesFinder.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <system_error>

using namespace std;

TEST_CASE( "List build dir files", "[files]" ) 
{
    auto files = getDirectoryFiles("."); 
    cout << files.size() << " files in the dir ." << endl;
    stringstream  s;

    copy(files.begin(), files.end(), ostream_iterator<string>(s, ","));
    cout <<  s.str()  << endl;

    for_each(files.begin(), files.end(), [](const string& n) { cout << n << endl; });
    
    REQUIRE_FALSE( files.empty() );
    REQUIRE( find(files.begin(), files.end(), "build.ninja") != files.end() );
    REQUIRE_THROWS_AS( getDirectoryFiles("nonexistentdir"), system_error );
}
