
#include <stdexcept>
#include "Content.h"

using namespace std;

Content::Content(ifstream in): 
    Content(string{istreambuf_iterator<char>{in}, istreambuf_iterator<char>{}})
{
}

Content::Content(const std::string & fileContent): _raw(fileContent)
{
    if (_raw.empty()) 
    {
        throw invalid_argument{"Cannot process empty content"};
    }
    _parse();
}

std::string Content::html()
{
    return _html;
}

void Content::_parse() 
{

}