#ifndef VIRTUALEXPRNODE_H
#define VIRTUALEXPRNODE_H

#include <basenode.h>
#include <type.h>

class VirtualExprNode : public BaseNode
{
protected:
    Type type;
public:
    VirtualExprNode(SymbolTable* symbolTable, int way);
    virtual Type getType();
};

#endif // VIRTUALEXPRNODE_H
