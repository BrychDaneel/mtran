#ifndef FORNODE_H
#define FORNODE_H

#include <basenode.h>

class ForNode : public BaseNode
{
protected:
    enum SubType{var, array} subType;
    int gid;
public:
    ForNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "ForNode";}
    void semantic() override;
    std::string getCode() override;
};

#endif // FORNODE_H
