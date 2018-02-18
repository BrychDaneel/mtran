#include "stringtoken.h"

const int StringToken::TYPE = 402;
const std::string StringToken::REGEX = "'..+?'" ;
const std::string StringToken::NAME = "String";


StringToken::StringToken(const std::string lexem)
{
    this->lexem = lexem;
    value = lexem.substr(0, lexem.size()-1);
}

Token *StringToken::create(const std::string lexem)
{
    return new StringToken(lexem);
}

std::string StringToken::getValue()
{
    return value;
}
