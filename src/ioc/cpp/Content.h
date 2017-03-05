
#include <string>
#include <fstream>

class Content {
    public:
        Content(std::ifstream input);
        Content(const std::string & fileContent);

        std::string html();
    private:
        void _parse();

        std::string _raw;
        std::string _html;
        
};