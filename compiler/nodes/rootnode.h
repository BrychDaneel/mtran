#ifndef ROOTNODE_H
#define ROOTNODE_H

#include <basenode.h>

class RootNode : public BaseNode
{
public:
    RootNode();
    std::string getName() {return "RootNode";}
};

#endif // ROOTNODE_H
