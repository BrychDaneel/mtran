#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
public:
    virtual void add(Node* node) = 0;
    virtual void print(int level=0) = 0;
    virtual void semantic() = 0;
    virtual std::string getCode() = 0;
    virtual std::string getName() = 0;
};

#endif // NODE_H
