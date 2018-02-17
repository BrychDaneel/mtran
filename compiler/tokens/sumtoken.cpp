#include "sumtoken.h"


const int SumToken::TYPE = 317;
const std::string SumToken::REGEX = "\\+|-" ;
const std::string SumToken::NAME = "sum";


SumToken::SumToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *SumToken::create(const std::string lexem)
{
    return new SumToken(lexem);
}
