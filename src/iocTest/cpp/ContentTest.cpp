#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "src/iocTest/cpp/catch.hpp"
#include "src/ioc/cpp/Content.h"

TEST_CASE( "Create Content from string", "[content]" ) {
    REQUIRE_THROWS( Content("") );
    REQUIRE( Content("asdf").html() == "" );
}