#include "emptyexprnode.h"

EmptyExprNode::EmptyExprNode(SymbolTable *symbolTable, int way)
    : VirtualExprNode(symbolTable, way)
{

}

void EmptyExprNode::semantic()
{
    VirtualExprNode* node = dynamic_cast<VirtualExprNode*>(nodes[0]);
    node->semantic();
    type = node->getType();
}

std::string EmptyExprNode::getCode()
{
    VirtualExprNode* node = dynamic_cast<VirtualExprNode*>(nodes[0]);
    node->setDist(dist, isLocal);
    return node->getCode();
}
