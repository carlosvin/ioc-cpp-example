
#include <dirent.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include "FilesFinder.h"

using namespace std;


vector<string> getDirectoryFiles(const string& dir) 
{
    vector<string> files;
    shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR* dir){ dir && closedir(dir); });
    struct dirent *dirent_ptr;
    if (!directory_ptr) {
        cout << "Error opening : " << strerror(errno) << dir << endl;
        return files;
    }
 
    while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) {
        files.push_back(string(dirent_ptr->d_name));
    }
    return files;
}