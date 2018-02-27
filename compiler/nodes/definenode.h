#ifndef DEFINENODE_H
#define DEFINENODE_H

#include <basenode.h>

class DefineNode : public BaseNode
{
protected:
    std::vector<int> idList;
    Type type;
public:
    DefineNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "DefineNode";}

    void semantic();
    std::string getCode() override;
};

#endif // DEFINENODE_H
