#ifndef DEFINENODE_H
#define DEFINENODE_H

#include <basenode.h>

class DefineNode : public BaseNode
{
public:
    DefineNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "DefineNode";}

    void semantic();
};

#endif // DEFINENODE_H
