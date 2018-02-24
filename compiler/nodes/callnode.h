#ifndef CALLNODE_H
#define CALLNODE_H

#include <basenode.h>

class CallNode : public BaseNode
{
protected:
    int gid;
public:
    CallNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "CallNode";}
    void semantic() override;
    void setGID(int gid);
};

#endif // CALLNODE_H
