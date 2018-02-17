#include "leftbracetoken.h"


const int LeftBraceToken::TYPE = 310;
const std::string LeftBraceToken::REGEX = "\\{" ;
const std::string LeftBraceToken::NAME = "leftbrace";


LeftBraceToken::LeftBraceToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *LeftBraceToken::create(const std::string lexem)
{
    return new LeftBraceToken(lexem);
}
