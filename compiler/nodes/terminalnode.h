#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include <basenode.h>
#include <token.h>

class TerminalNode : public BaseNode
{
    Token* token;

public:
    TerminalNode(Token* token);
    void print(int level=0);
};

#endif // TERMINALNODE_H
