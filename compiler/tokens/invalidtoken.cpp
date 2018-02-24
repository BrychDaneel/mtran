#include "invalidtoken.h"


#include <iostream>

const int InvalidToken::TYPE = 3;
const std::string InvalidToken::REGEX = "\\S+" ;
const std::string InvalidToken::NAME = "Invalid";


InvalidToken::InvalidToken(const std::string lexem)
{
    this->lexem = lexem;

}

Token *InvalidToken::create(const std::string lexem)
{
    return new InvalidToken(lexem);
}

