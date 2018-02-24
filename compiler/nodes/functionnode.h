#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include <basenode.h>

class FunctionNode : public BaseNode
{
protected:
    int isProc;
    Signature sig;
    std::vector<int> paramsGID;
public:
    FunctionNode(SymbolTable *symbolTable, int way, bool isProc);
    std::string getName() {return "FunctionNode";}
    void semantic();
};

#endif // FUNCTIONNODE_H
