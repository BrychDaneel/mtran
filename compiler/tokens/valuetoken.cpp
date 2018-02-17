#include "valuetoken.h"


const int ValueToken::TYPE = 318;
const std::string ValueToken::REGEX = "\\^" ;
const std::string ValueToken::NAME = "value";


ValueToken::ValueToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *ValueToken::create(const std::string lexem)
{
    return new ValueToken(lexem);
}
