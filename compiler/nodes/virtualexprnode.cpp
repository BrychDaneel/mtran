#include "virtualexprnode.h"

#include <iostream>
#include <sstream>

VirtualExprNode::VirtualExprNode(SymbolTable *symbolTable, int way)
    : BaseNode(symbolTable, way)
{

}

Type VirtualExprNode::getType()
{
    return type;
}

void VirtualExprNode::setDist(int dist, bool isLocal)
{
    this->dist = dist;
    this->isLocal = isLocal;
}

std::string VirtualExprNode::strAdress()
{
    std::stringstream buf;
    if (isLocal)
        buf << "$";
    else
        buf << "#";
    buf << dist;
    return buf.str();
}

void VirtualExprNode::printTypes(int level)
{
    for (int i=0; i<level*2; i++)
        std::cout << " ";
    std::cout << type.getStr() << std::endl;

    for (Node* node : nodes)
        node->printTypes(level + 1);
}
