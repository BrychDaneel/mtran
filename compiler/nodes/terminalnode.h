#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include <basenode.h>
#include <token.h>

class TerminalNode : public BaseNode
{
    Token* token;

public:
    TerminalNode(SymbolTable *symbolTable, Token* token);
    void print(int level=0);
    void printTypes(int level=0);
    Token* getToken();
    int getLine() override;
    int getPos() override;
};

#endif // TERMINALNODE_H
