
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
    if (!directory_ptr) 
    {
        throw system_error(error_code(errno, system_category()), "Error opening : " + dir);
    }
 
    struct dirent *dirent_ptr;
    while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) 
    {
        const string fileName {dirent_ptr->d_name};
        if (dirent_ptr->d_type == DT_DIR) 
        {
            if (CURRENT_DIR != fileName && UP_DIR != fileName) 
            {
                auto subFiles = getDirectoryFiles(path({dir, fileName}));
                files.insert(end(files), begin(subFiles), end(subFiles));
            }
        } 
        else if (dirent_ptr->d_type == DT_REG) 
        {
            files.push_back(path({dir, fileName}));
        }
    }
    return files;
}

string path(initializer_list<string> parts) 
{
    string pathTmp {};
    string separator = "";
    for (auto & part: parts) 
    {
        pathTmp.append(separator).append(part);
        separator = SEP;
    }
    return pathTmp;
}