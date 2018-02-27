#ifndef CONTROLNODE_H
#define CONTROLNODE_H

#include <basenode.h>

class ControlNode : public BaseNode
{
public:
    ControlNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "ControlNode";}
    void semantic() override;
    std::string getCode() override;
};

#endif // CONTROLNODE_H
