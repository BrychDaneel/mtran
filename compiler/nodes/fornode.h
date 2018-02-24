#ifndef FORNODE_H
#define FORNODE_H

#include <basenode.h>

class ForNode : public BaseNode
{
public:
    ForNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "ForNode";}
    void semantic() override;
};

#endif // FORNODE_H
