
#include <string>
#include <vector>
#include <initializer_list>

inline char separator()
{
#ifdef _WIN32
    return '\\';
#else
    return '/';
#endif
}

#ifdef _WIN32
const std::string SEP = "\\";
#else
const std::string SEP = "/";
#endif


const std::string CURRENT_DIR {"."};
const std::string UP_DIR {".."};

std::vector<std::string> getDirectoryFiles(const std::string& dir);

std::string path(std::initializer_list<std::string> parts);
