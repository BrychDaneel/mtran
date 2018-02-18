#include "chartoken.h"


const int CharToken::TYPE = 403;
const std::string CharToken::REGEX = "'.'" ;
const std::string CharToken::NAME = "char";


CharToken::CharToken(const std::string lexem)
{
    this->lexem = lexem;
    chr = lexem[1];
}

Token *CharToken::create(const std::string lexem)
{
    return new CharToken(lexem);
}

char CharToken::getValue()
{
    return chr;
}

