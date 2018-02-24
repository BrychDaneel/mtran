#ifndef IDLISTNODE_H
#define IDLISTNODE_H

#include <basenode.h>
#include <vector>

class IdListNode : public BaseNode
{
    std::vector<int> idList;
    bool first;
public:
    IdListNode(SymbolTable *symbolTable, int way, bool first);
    std::string getName() {return "IdListNode";}

    void semantic();
    std::vector<int> getIdList();
};

#endif // IDLISTNODE_H
