#ifndef PARAMSNODE_H
#define PARAMSNODE_H

#include <basenode.h>

class ParamsNode : public BaseNode
{
    bool midle;
    std::vector<Type> types;
public:
    ParamsNode(SymbolTable *symbolTable, int way, bool midle);
    std::string getName() override {return "ParamsNode";}
    void semantic() override;
    void setTypes(std::vector<Type> types);
};

#endif // PARAMSNODE_H
