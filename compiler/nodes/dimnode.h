#ifndef DIMNODE_H
#define DIMNODE_H

#include <basenode.h>
#include <vector>

class DimNode : public BaseNode
{
    bool first;
    std::vector<int> start;
    std::vector<int> dimSize;
public:
    DimNode(SymbolTable *symbolTable, int way, bool first);
    std::string getName() {return "DimNode";}
    void semantic();

    std::vector<int> getStart();
    std::vector<int> getDimSize();
};

#endif // DIMNODE_H
