#ifndef SIGNODE_H
#define SIGNODE_H

#include <basenode.h>

class SigNode : public BaseNode
{
protected:
    bool first;
    Signature sig;
    std::vector<int> idList;
public:
    SigNode(SymbolTable *symbolTable, int way, bool first);
    std::string getName() {return "SigNode";}
    void semantic() override;

    Signature getSig();
    std::vector<int> getIdList();
};

#endif // SIGNODE_H
