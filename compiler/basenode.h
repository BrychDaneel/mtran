#ifndef BASENODE_H
#define BASENODE_H

#include <node.h>
#include <vector>

class BaseNode : public Node
{
    int way = -1;
    std::vector<Node*> nodes;

public:
    BaseNode();
    BaseNode(int way);
    void add(Node* node);
    void print(int level=0);
    void semantic() {}
    std::string getCode() {return "";}
    std::string getName() {return "BaseNode";}
};

#endif // BASENODE_H
