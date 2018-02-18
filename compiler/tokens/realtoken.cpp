#include "realtoken.h"
#include <iostream>

const int RealToken::TYPE = 401;
const std::string RealToken::REGEX = "(\\d*(\\.\\d+)?(E|e)(\\+|-)?\\d+)|(\\d*\\.\\d+)" ;
const std::string RealToken::NAME = "real";


RealToken::RealToken(const std::string lexem)
{
    this->lexem = lexem;
    if (sscanf(lexem.c_str(), "%g", &value) != 1){
        std::cerr << "Can't convert Real!" << std::endl;
        exit(1);
    }
}

Token *RealToken::create(const std::string lexem)
{
    return new RealToken(lexem);
}

double RealToken::getValue()
{
    return value;
}
