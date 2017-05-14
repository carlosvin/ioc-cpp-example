#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "src/FilesFinder.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <system_error>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

using namespace std;

TEST_CASE( "List build dir files", "[files]" ) 
{

	const auto f = fs::path("./asdf.asdf").string();
	std::ofstream{ f } << "test";

	auto files = getDirectoryFiles(".");
    cout << files.size() << " files in the dir ." << endl;

    REQUIRE_FALSE( files.empty() );

	REQUIRE_THAT(files, Catch::Matchers::VectorContains(f));

    REQUIRE( getDirectoryFiles("nonexistentdir").empty());
}

TEST_CASE("Filter files", "[files]")
{
	fs::create_directories("sandbox/a/b");
	vector<string> e_files = {
		fs::path("./sandbox/a/b/file1.rst").string(), 
		fs::path("./sandbox/a/file2.RST").string(),
		fs::path("./sandbox/file3.md").string() 
	};

	for (auto f: e_files)
	{
		std::ofstream {f} << "test";
	}
	
	vector<string> o_files = getDirectoryFiles(".", {".rst", ".RST", ".md"});

	sort(begin(e_files), end(e_files));
	sort(begin(o_files), end(o_files));

	REQUIRE_THAT(e_files, Catch::Matchers::Equals(o_files));
}
