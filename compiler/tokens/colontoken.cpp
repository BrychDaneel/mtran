#include "colontoken.h"


const int ColonToken::TYPE = 304;
const std::string ColonToken::REGEX = ":" ;
const std::string ColonToken::NAME = "colon";


ColonToken::ColonToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *ColonToken::create(const std::string lexem)
{
    return new ColonToken(lexem);
}
