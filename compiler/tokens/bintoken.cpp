#include "bintoken.h"


const int BinToken::TYPE = 303;
const std::string BinToken::REGEX = "\\+|-" ;
const std::string BinToken::NAME = "bin";


BinToken::BinToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *BinToken::create(const std::string lexem)
{
    return new BinToken(lexem);
}
