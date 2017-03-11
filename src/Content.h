
#include <string>
#include <fstream>

class Content {
    public:
        Content(std::ifstream & input);
        Content(const std::string & fileContent);

        std::string html();
        std::ostream& operator << ( std::ostream& os ) const;
    private:
        static std::string _parse(const std::string & raw);

        std::string _raw;
        std::string _html;
        
};