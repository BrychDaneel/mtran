#include "convertnode.h"
#include <iostream>

ConvertNode::ConvertNode(SymbolTable* symbolTable, VirtualExprNode* node, Type type)
    : VirtualExprNode(symbolTable, 0)
{
    if (type.getBaseType() == BaseType::_void){
        std::cerr << "Invalid operand type" << std::endl;
        exit(1);
    }

    this->type = type;
    nodes.push_back(node);

}

Type ConvertNode::getType()
{
    return type;
}
