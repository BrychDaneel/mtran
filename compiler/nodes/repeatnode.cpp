#include "repeatnode.h"

#include <nodes/virtualexprnode.h>
#include <iostream>

RepeatNode::RepeatNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void RepeatNode::semantic()
{
    nodes[3]->semantic();
    Type type = dynamic_cast<VirtualExprNode*>(nodes[3])->getType();
    if (!type.isSimple() || type.getBaseType() != BaseType::_boolean){
        std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Condition must be boolean" << std::endl;
        exit(1);
    }
    nodes[1]->semantic();
}
