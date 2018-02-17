#include "realtoken.h"


const int RealToken::TYPE = 401;
const std::string RealToken::REGEX = "(\\d*(\\.\\d+)?(E|e)(\\+|-)?\\d+)|(\\d*\\.\\d+)" ;
const std::string RealToken::NAME = "real";


RealToken::RealToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *RealToken::create(const std::string lexem)
{
    return new RealToken(lexem);
}
