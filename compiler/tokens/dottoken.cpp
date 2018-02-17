#include "dottoken.h"


const int DotToken::TYPE = 307;
const std::string DotToken::REGEX = "\\." ;
const std::string DotToken::NAME = "dot";


DotToken::DotToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *DotToken::create(const std::string lexem)
{
    return new DotToken(lexem);
}
