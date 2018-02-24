#ifndef LITERALNODE_H
#define LITERALNODE_H

#include <nodes/virtualexprnode.h>

class LiteralNode : public VirtualExprNode
{
public:
    LiteralNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "LiteralNode";}
    void semantic();
};

#endif // LITERALNODE_H
