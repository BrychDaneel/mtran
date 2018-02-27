#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include <basenode.h>

class FunctionNode : public BaseNode
{
protected:
    int gid;
    int isProc;
    Signature sig;
    std::vector<int> paramsGID;
    Type returnType;
    int funDif = 0;
public:
    FunctionNode(SymbolTable *symbolTable, int way, bool isProc);
    std::string getName() {return "FunctionNode";}
    void semantic();
    std::string getCode() override;
};

#endif // FUNCTIONNODE_H
