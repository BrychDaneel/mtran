#include "leftbrackettoken.h"


const int LeftBracketToken::TYPE = 311;
const std::string LeftBracketToken::REGEX = "\\(" ;
const std::string LeftBracketToken::NAME = "leftbracket";


LeftBracketToken::LeftBracketToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *LeftBracketToken::create(const std::string lexem)
{
    return new LeftBracketToken(lexem);
}
