#include "assigntoken.h"


const int AssignToken::TYPE = 302;
const std::string AssignToken::REGEX = ":=" ;
const std::string AssignToken::NAME = "assign";


AssignToken::AssignToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *AssignToken::create(const std::string lexem)
{
    return new AssignToken(lexem);
}
