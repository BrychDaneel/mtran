#include "terminalnode.h"
#include <iostream>


TerminalNode::TerminalNode(SymbolTable* symbolTable, Token *token)
    : BaseNode(symbolTable, 0)
{
    this->token = token;
}

void TerminalNode::print(int level)
{
    for (int i=0; i<level*2; i++)
        std::cout << " ";
    std::cout << token->getLexem() << std::endl;
}

Token *TerminalNode::getToken()
{
    return token;
}

int TerminalNode::getLine()
{
    return token->getLine();
}

int TerminalNode::getPos()
{
    return token->getPos();
}
