#include "semicolontoken.h"


const int SemicolonToken::TYPE = 316;
const std::string SemicolonToken::REGEX = ";" ;
const std::string SemicolonToken::NAME = "semicolon";


SemicolonToken::SemicolonToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *SemicolonToken::create(const std::string lexem)
{
    return new SemicolonToken(lexem);
}
