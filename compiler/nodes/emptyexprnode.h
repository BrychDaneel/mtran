#ifndef EMPTYEXPRNODE_H
#define EMPTYEXPRNODE_H

#include <nodes/virtualexprnode.h>

class EmptyExprNode : public VirtualExprNode
{
public:
    EmptyExprNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "EmptyExprNode";}
    void semantic();
};

#endif // EMPTYEXPRNODE_H
