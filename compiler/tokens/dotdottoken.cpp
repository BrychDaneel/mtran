#include "dotdottoken.h"


const int DotDotToken::TYPE = 306;
const std::string DotDotToken::REGEX = "\\.\\." ;
const std::string DotDotToken::NAME = "dotdot";


DotDotToken::DotDotToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *DotDotToken::create(const std::string lexem)
{
    return new DotDotToken(lexem);
}
