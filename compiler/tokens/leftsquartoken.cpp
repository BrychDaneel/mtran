#include "leftsquartoken.h"


const int LeftSquarToken::TYPE = 312;
const std::string LeftSquarToken::REGEX = "\\[" ;
const std::string LeftSquarToken::NAME = "feftsquar";


LeftSquarToken::LeftSquarToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *LeftSquarToken::create(const std::string lexem)
{
    return new LeftSquarToken(lexem);
}
