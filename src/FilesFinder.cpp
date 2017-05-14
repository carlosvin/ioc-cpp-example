
#include <experimental/filesystem>
#include <iostream>
#include <vector>
#include <memory>
#include <system_error>
#include "FilesFinder.h"

namespace fs = std::experimental::filesystem;
using namespace std;

vector<string> getDirectoryFiles(const string & dir, const vector<string> & extensions) 
{
	vector<string> files;
    for(auto & p: fs::recursive_directory_iterator(dir)) 
    {
        if (fs::is_regular_file(p)) 
        {
	        if (extensions.empty() || find(extensions.begin(), extensions.end(), p.path().extension().string()) != extensions.end()) 
            {
                files.push_back(p.path().string());
            } 
        }
    }
    return files;    
}
