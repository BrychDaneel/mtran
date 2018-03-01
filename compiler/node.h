#ifndef NODE_H
#define NODE_H

#include <string>
#include <symboltable.h>

class Node
{
public:
    virtual void add(Node* node) = 0;
    virtual void print(int level=0) = 0;
    virtual void printTypes(int level=0) = 0;
    virtual void semantic() = 0;
    virtual std::string getCode() = 0;
    virtual std::string getName() = 0;
    virtual SymbolTable* getSymbolTable() = 0;
    virtual int getWay() = 0;
    virtual std::vector<Node*> getNodes() = 0;
    virtual int getLine() = 0;
    virtual int getPos() = 0;
};

#endif // NODE_H
