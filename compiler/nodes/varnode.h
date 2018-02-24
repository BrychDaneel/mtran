#ifndef VARNODE_H
#define VARNODE_H



#include <nodes/virtualexprnode.h>
#include <type.h>


class VarNode : public VirtualExprNode
{
public:
    VarNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "VarNode";}
    void semantic();
};

#endif // VARNODE_H
