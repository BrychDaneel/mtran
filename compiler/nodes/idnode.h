#ifndef IDNODE_H
#define IDNODE_H

#include <basenode.h>

class IdNode : public BaseNode
{
    int gid;
public:
    IdNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "IdNode";}

    void semantic();
    int getGID();
};

#endif // VARSTARTNODE_H
