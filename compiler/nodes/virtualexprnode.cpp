#include "virtualexprnode.h"

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


