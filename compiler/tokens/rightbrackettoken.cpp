#include "rightbrackettoken.h"


const int RightBracketToken::TYPE = 314;
const std::string RightBracketToken::REGEX = "\\)" ;
const std::string RightBracketToken::NAME = "rightbracket";


RightBracketToken::RightBracketToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *RightBracketToken::create(const std::string lexem)
{
    return new RightBracketToken(lexem);
}
