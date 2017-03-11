
#include <dirent.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include <system_error>
#include "FilesFinder.h"

using namespace std;

vector<string> getDirectoryFiles(const string& dir) 
{
    vector<string> files;
    shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR* dir){ dir && closedir(dir); });
    if (!directory_ptr) {
        throw system_error(error_code(errno, system_category()), "Error opening : " + dir);
    }
 
    struct dirent *dirent_ptr;
    while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) {
        files.push_back(string(dirent_ptr->d_name));
    }
    return files;
}