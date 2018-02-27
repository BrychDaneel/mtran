#include "stringtoken.h"

const int StringToken::TYPE = 402;
const std::string StringToken::REGEX = "'..+?'" ;
const std::string StringToken::NAME = "String";


StringToken::StringToken(const std::string lexem)
{
    this->lexem = lexem;
    value = lexem.substr(1, lexem.size()-2);
}

Token *StringToken::create(const std::string lexem)
{
    return new StringToken(lexem);
}

std::string StringToken::getValue()
{
    return value;
}
