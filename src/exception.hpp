#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

namespace chen
{

class Exception
{
private:
    std::string whatString;
public:
    Exception(): whatString("Chen exception.") {}
    Exception(std::string what, std::string file, int line): whatString("Chen exception. File: " + file + "; Line: " + std::to_string(line) + "; What: " + what) {}

    inline std::string what() { return whatString; }
};

}

#endif // EXCEPTION_HPP