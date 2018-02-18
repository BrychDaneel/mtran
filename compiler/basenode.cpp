#include "basenode.h"


BaseNode::BaseNode(int way)
{
    this->way = way;
}

void BaseNode::add(Node *node)
{
    nodes.push_back(node);
}
