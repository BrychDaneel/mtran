#include "callnode.h"

#include <nodes/paramsnode.h>

CallNode::CallNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void CallNode::semantic()
{

    dynamic_cast<ParamsNode*>(nodes[1])->setTypes(symbolTable->getSignatyre(gid)->getParams());
    nodes[1]->semantic();
}

void CallNode::setGID(int gid)
{
    this->gid = gid;
}
