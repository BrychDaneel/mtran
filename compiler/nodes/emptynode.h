#ifndef EMPTYNODE_H
#define EMPTYNODE_H

#include <basenode.h>

class EmptyNode : public BaseNode
{
public:
    EmptyNode();
    std::string getName() {return "EmptyNode";}
    std::string getCode() override {return "";}
};

#endif // EMPTYNODE_H
