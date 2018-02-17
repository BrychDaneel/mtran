#include "codesource.h"

#include <iostream>


CodeSource::CodeSource(const std::string filename)
    : file(filename)
{

    if (!file.is_open()){
        std::cerr << "ERROR: Can't open file" << std::endl;
        exit(1);
    }

    current = file.get();
}

char CodeSource::pop()
{
    int prev = current;
    current = file.get();
    return prev;
}

char CodeSource::front()
{
    return current;
}

bool CodeSource::finished()
{
    return current == -1;
}

const std::string CodeSource::full()
{
    std::string s;
    std::getline(file, s, '\0');
    return (char)current + s;
}
