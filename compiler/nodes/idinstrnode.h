#ifndef IDINSTRNODE_H
#define IDINSTRNODE_H


#include <basenode.h>


class IdInstrNode : public BaseNode
{
protected:
    bool start;
    int gid;
public:
    IdInstrNode(SymbolTable *symbolTable, int way, bool start);
    void setGID(int gid);
    std::string getName() {return "IdInstrNode";}
    void semantic();
};

#endif // IDINSTRNODE_H
