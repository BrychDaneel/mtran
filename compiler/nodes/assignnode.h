#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H

#include <basenode.h>

class AssignNode : public BaseNode
{
    Type requiredType;
public:
    AssignNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "AssignNode";}
    void semantic();
    void setRequiredType(Type requiredType);
};

#endif // ASSIGNNODE_H
