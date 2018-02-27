#ifndef UNARNODE_H
#define UNARNODE_H

#include <nodes/virtualexprnode.h>

class UnarNode : public VirtualExprNode
{
    enum SubType{_plus, _minus, _not} subType;
public:
    UnarNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "CompareNode";}
    void semantic();
    std::string getCode() override;
};

#endif // OPERANDNODE_H
