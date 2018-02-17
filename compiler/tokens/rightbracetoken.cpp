#include "rightbracetoken.h"


const int RightBraceToken::TYPE = 313;
const std::string RightBraceToken::REGEX = "\\}" ;
const std::string RightBraceToken::NAME = "rightbrace";


RightBraceToken::RightBraceToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *RightBraceToken::create(const std::string lexem)
{
    return new RightBraceToken(lexem);
}
