#include "virtualexprnode.h"


VirtualExprNode::VirtualExprNode(SymbolTable *symbolTable, int way)
    : BaseNode(symbolTable, way)
{

}

Type VirtualExprNode::getType()
{
    return type;
}
