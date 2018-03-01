#ifndef VIRTUALEXPRNODE_H
#define VIRTUALEXPRNODE_H

#include <basenode.h>
#include <type.h>

class VirtualExprNode : public BaseNode
{
protected:
    Type type;
    int dist;
    bool isLocal;
public:
    VirtualExprNode(SymbolTable* symbolTable, int way);
    virtual Type getType();
    virtual void setDist(int dist, bool isLocal);
    virtual std::string strAdress();
    virtual void printTypes(int level);
};

#endif // VIRTUALEXPRNODE_H
