#ifndef CONVERTNODE_H
#define CONVERTNODE_H

#include <nodes/virtualexprnode.h>

class ConvertNode : public VirtualExprNode
{
    Type type;
public:
    ConvertNode(SymbolTable *symbolTable, VirtualExprNode* node, Type type);
    Type getType();
};

#endif // CONVERTNODE_H
