#include "token.h"

const std::string Token::getLexem()
{
    return lexem;
}

void Token::setLine(int line)
{
    this->line = line;
}

void Token::setPos(int pos)
{
    this->pos = pos;
}

int Token::getLine()
{
    return line;
}

int Token::getPos()
{
    return pos;
}
