#ifndef RANGENODE_H
#define RANGENODE_H


#include <basenode.h>

class RangeNode : public BaseNode
{
    int start;
    int end;
public:
    RangeNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "RangeNode";}
    void semantic();
    int getStart();
    int getEnd();
};

#endif // RANGENODE_H
