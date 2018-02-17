#include "adresstoken.h"

const int AdressToken::TYPE = 301;
const std::string AdressToken::REGEX = "@" ;
const std::string AdressToken::NAME = "adress";


AdressToken::AdressToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *AdressToken::create(const std::string lexem)
{
    return new AdressToken(lexem);
}
