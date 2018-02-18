#ifndef BASENODE_H
#define BASENODE_H

#include <node.h>
#include <vector>

class BaseNode : public Node
{
    int way;
    std::vector<Node*> nodes;

public:
    BaseNode(int way);
    void add(Node* node);
};

#endif // BASENODE_H
