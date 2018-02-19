#include "terminalnode.h"
#include <iostream>


TerminalNode::TerminalNode(Token *token)
{
    this->token = token;
}

void TerminalNode::print(int level)
{
    for (int i=0; i<level*2; i++)
        std::cout << " ";
    std::cout << token->getLexem() << std::endl;
}
