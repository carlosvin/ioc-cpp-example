#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "src/Content.h"

#include <fstream>

TEST_CASE( "Create Content from string", "[content][string]" ) 
{
    REQUIRE_THROWS( Content("") );
    REQUIRE( Content("asdf").html() == "<html>asdf</html>" );
}

TEST_CASE( "Create Content from non existent file", "[content][file]" ) 
{
    std::ifstream t{"file.txt"};
    REQUIRE_THROWS(Content{t});
}

TEST_CASE( "Create Content from file", "[content][file]" ) 
{
    std::ifstream t{"example.txt"};
    REQUIRE( Content(t).html() == "<html>asdf</html>" );
}