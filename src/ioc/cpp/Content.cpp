
#include <stdexcept>
#include "Content.h"

using namespace std;

Content::Content(ifstream & in): 
    Content(string{istreambuf_iterator<char>{in}, istreambuf_iterator<char>{}})
{}

Content::Content(const string & fileContent): 
    _raw(fileContent), _html(_parse(fileContent))
{}

string Content::html()
{
    return _html;
}

string Content::_parse(const string & raw) 
{
    if (raw.empty()) 
    {
        throw invalid_argument{"Cannot process empty content"};
    }
    return "<html>" + raw + "</html>";
}

ostream& Content::operator << ( ostream& os ) const {
    os << _raw;
    return os;
}