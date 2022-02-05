#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

#define CHEN_EXCEPTION(what) chen::Exception(what, __FILE__, __LINE__);

namespace chen
{

class Exception
{
private:
    std::string whatString;
public:
    Exception(): whatString("Chen exception.") {}
    Exception(std::string what, std::string file, int line): whatString("Chen exception. File: " + file + "; Line: " + std::to_string(line) + "; What: " + what) {}

    inline std::string what() const { return whatString; }
};

}

#endif // EXCEPTION_HPP