#include "ynartoken.h"


const int YnarToken::TYPE = 320;
const std::string YnarToken::REGEX = "(_|[a-zA-Z])\\w*" ;
const std::string YnarToken::NAME = "Ynar";


YnarToken::YnarToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *YnarToken::create(const std::string lexem)
{
    return new YnarToken(lexem);
}
