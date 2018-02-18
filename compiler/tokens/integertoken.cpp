#include "integertoken.h"
#include <cstdio>
#include <iostream>

const int IntegerToken::TYPE = 400;
const std::string IntegerToken::REGEX = "\\d+" ;
const std::string IntegerToken::NAME = "Integer";


IntegerToken::IntegerToken(const std::string lexem)
{
    this->lexem = lexem;
    if (sscanf(lexem.c_str(), "%d", &value) != 1){
        std::cerr << "Can't convert Integer!" << std::endl;
        exit(1);
    }
}

Token *IntegerToken::create(const std::string lexem)
{
    return new IntegerToken(lexem);
}

int IntegerToken::getValue()
{
    return value;
}
