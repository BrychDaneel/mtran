#ifndef IFNODE_H
#define IFNODE_H

#include <basenode.h>

class IfNode : public BaseNode
{
public:
    IfNode(SymbolTable *symbolTable, int way);
    std::string getName() override {return "IfNode";}
    void semantic() override;
    std::string getCode() override;
};

#endif // IFNODE_H
