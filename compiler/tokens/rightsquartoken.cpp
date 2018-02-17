#include "rightsquartoken.h"


const int RightSquarToken::TYPE = 315;
const std::string RightSquarToken::REGEX = "\\]" ;
const std::string RightSquarToken::NAME = "rightsquar";


RightSquarToken::RightSquarToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *RightSquarToken::create(const std::string lexem)
{
    return new RightSquarToken(lexem);
}
