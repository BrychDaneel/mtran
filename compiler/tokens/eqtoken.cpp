#include "eqtoken.h"


const int EQToken::TYPE = 308;
const std::string EQToken::REGEX = "=|<>|>=|<=|>|<" ;
const std::string EQToken::NAME = "eq";


EQToken::EQToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *EQToken::create(const std::string lexem)
{
    return new EQToken(lexem);
}
