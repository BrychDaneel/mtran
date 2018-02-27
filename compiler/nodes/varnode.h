#ifndef VARNODE_H
#define VARNODE_H



#include <nodes/virtualexprnode.h>
#include <type.h>


class VarNode : public VirtualExprNode
{
protected:
    int gid;
public:
    enum SubType {_var, _fun, _array, _literal, _expr, _string} subType;
    VarNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "VarNode";}
    void semantic();
    std::string getCode() override;
};

#endif // VARNODE_H
