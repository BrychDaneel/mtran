#include "stringtoken.h"

const int StringToken::TYPE = 402;
const std::string StringToken::REGEX = "'.{2,}'" ;
const std::string StringToken::NAME = "String";


StringToken::StringToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *StringToken::create(const std::string lexem)
{
    return new StringToken(lexem);
}
