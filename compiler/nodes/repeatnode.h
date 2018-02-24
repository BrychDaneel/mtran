#ifndef REPEATNODE_H
#define REPEATNODE_H

#include <basenode.h>

class RepeatNode : public BaseNode
{
public:
    RepeatNode(SymbolTable *symbolTable, int way);
    std::string getName() override {return "RepeatNode";}
    void semantic() override;
};

#endif // REPEATNODE_H
