#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H

#include <basenode.h>

class AssignNode : public BaseNode
{
    Type requiredType;
    int adress;
    bool isLocal;
    bool isRel;
public:
    AssignNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "AssignNode";}
    void semantic();
    void setRequiredType(Type requiredType);
    void setAdress(int adress, bool isLocal, bool isRel);
    std::string getCode() override;
};

#endif // ASSIGNNODE_H
