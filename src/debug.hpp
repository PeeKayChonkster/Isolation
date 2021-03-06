#ifndef CHEN_DEBUG_HPP
#define CHEN_DEBUG_HPP

#include <raylib-cpp.hpp>
#include <vector>
#include <string>
#include <iostream>

namespace chen
{
    typedef unsigned int uint;

    class Debug
    {
    private:
        inline static std::pair<int, int> textPosition = { 5, 50 };
        inline static std::vector<std::string> lines = {};
        inline static std::vector<std::string> persistentLines = {};
    public:
        inline static int fontSize = 14;

        inline static void printLine(std::string line)
        {
            //std::cout << "CHEN: pushed line: " + line << std::endl;
            lines.push_back(std::move(line));
        }

        inline static void printPersistentLine(std::string line)
        {
            //std::cout << "CHEN: pushed persistent line: " + line << std::endl;
            persistentLines.push_back(std::move(line));
        }

        inline static void draw()
        {
            uint i;
            for(i = 0u; i < persistentLines.size(); ++i)
                DrawText(persistentLines[i].c_str(), textPosition.first, textPosition.second + (i + 1u) * fontSize, fontSize, WHITE);

            for(uint j = 0u; j < lines.size(); ++i, ++j)
                DrawText(lines[j].c_str(), textPosition.first, textPosition.second + (i + 1u) * fontSize, fontSize, WHITE);
            
            lines.clear();
        }
    };
}

#endif // CHEN_DEBUG_HPP