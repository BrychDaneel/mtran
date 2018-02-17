#include "integertoken.h"


const int IntegerToken::TYPE = 400;
const std::string IntegerToken::REGEX = "\\d+" ;
const std::string IntegerToken::NAME = "Integer";


IntegerToken::IntegerToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *IntegerToken::create(const std::string lexem)
{
    return new IntegerToken(lexem);
}
