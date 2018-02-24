#include "ifnode.h"

#include <nodes/virtualexprnode.h>
#include <iostream>

IfNode::IfNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void IfNode::semantic()
{
    nodes[1]->semantic();
    Type type = dynamic_cast<VirtualExprNode*>(nodes[1])->getType();
    if (!type.isSimple() || type.getBaseType() != BaseType::_boolean){
        std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Condition must be boolean" << std::endl;
        exit(1);
    }
    nodes[3]->semantic();
}
