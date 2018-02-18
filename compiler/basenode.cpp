#include "basenode.h"
#include <iostream>

BaseNode::BaseNode()
{

}

BaseNode::BaseNode(int way)
{
    this->way = way;
}

void BaseNode::add(Node *node)
{
    nodes.push_back(node);
}

void BaseNode::print(int level)
{
    for (int i=0; i<level*4; i++)
        std::cout << " ";
    std::cout << getName() << std::endl;

    for (Node* node : nodes)
        node->print(level + 1);
}
