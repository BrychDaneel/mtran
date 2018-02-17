#include "comatoken.h"


const int ComaToken::TYPE = 305;
const std::string ComaToken::REGEX = "," ;
const std::string ComaToken::NAME = "coma";


ComaToken::ComaToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *ComaToken::create(const std::string lexem)
{
    return new ComaToken(lexem);
}
