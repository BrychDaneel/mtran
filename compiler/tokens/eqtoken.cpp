#include "eqtoken.h"
#include <iostream>

const int EQToken::TYPE = 308;
const std::string EQToken::REGEX = "=|(<>)|(>=)|(<=)|>|<" ;
const std::string EQToken::NAME = "eq";


EQToken::EQToken(const std::string lexem)
{
    this->lexem = lexem;
    if (lexem == "=")
        subType = SubType::ce;
    else if (lexem == "<>")
        subType = SubType::cne;
    else if (lexem == "<")
        subType = SubType::cb;
    else if (lexem == ">")
        subType = SubType::ca;
    else if (lexem == "<=")
        subType = SubType::cbe;
    else if (lexem == ">=")
        subType = SubType::cae;
    else{
        std::cerr << "Invalid EQ token" << std::endl;
        exit(1);
    }
}

Token *EQToken::create(const std::string lexem)
{
    return new EQToken(lexem);
}
