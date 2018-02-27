#ifndef CALLNODE_H
#define CALLNODE_H

#include <basenode.h>

class CallNode : public BaseNode
{
protected:
    int gid;
    bool isUser;
    std::vector<Type> paramsTypes;
    Fun* fun;
    int destAdress = -1;
    bool destIsLocal = true;
public:
    CallNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "CallNode";}
    void semantic() override;
    void setGID(int gid);
    Type getRetType();
    std::string getCode() override;
    virtual void setDist(int dist, bool isLocal);
};

#endif // CALLNODE_H
