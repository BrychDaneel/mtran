#include "syntaxanalizer.h"

SyntaxAnalizer::SyntaxAnalizer(std::string filename)
    : lex(filename)
{
    rule = RootRule::getInstance();
    rule->build();
}

Node *SyntaxAnalizer::parce()
{
    return rule->parce(&lex);
}
