#include "facttoken.h"


const int FactToken::TYPE = 309;
const std::string FactToken::REGEX = "\\*|\\/" ;
const std::string FactToken::NAME = "fact";


FactToken::FactToken(const std::string lexem)
{
    this->lexem = lexem;
    if (lexem == "*")
        subType = SubType::mult;
    else
        subType = SubType::div;
}

Token *FactToken::create(const std::string lexem)
{
    return new FactToken(lexem);
}
