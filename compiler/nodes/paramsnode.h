#ifndef PARAMSNODE_H
#define PARAMSNODE_H

#include <basenode.h>

class ParamsNode : public BaseNode
{
    bool midle;
    std::vector<Type> types;
    bool buildIn = false;
    std::vector<int> distList;
    std::vector<bool> isLocalList;
public:
    ParamsNode(SymbolTable *symbolTable, int way, bool midle);
    std::string getName() override {return "ParamsNode";}
    void semantic() override;
    void setTypes(std::vector<Type> types);

    void setBuildIn(bool isBuildIn);
    std::vector<Type> getTypes();

    void setDistList(std::vector<int> distList, std::vector<bool> isLocalList);

    std::string getCode() override;
};

#endif // PARAMSNODE_H
