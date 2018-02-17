#ifndef CODESOURCE_H
#define CODESOURCE_H


#include <fstream>


class CodeSource
{
    std::ifstream file;
    int current;

public:
    CodeSource(const std::string filename);
    char pop();
    char front();
    bool finished();
    const std::string full();
};

#endif // CODESOURCE_H
