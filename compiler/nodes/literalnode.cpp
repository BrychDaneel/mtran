#include "literalnode.h"

#include <iostream>

LiteralNode::LiteralNode(SymbolTable* symbolTable, int way)
    :VirtualExprNode(symbolTable, way)
{
}

void LiteralNode::semantic()
{
switch (way) {
case 0:
    type = Type(BaseType::_integer);
    break;
case 1:
    type = Type(BaseType::_real);
    break;
case 2:
    type = Type(BaseType::_char);
    break;
case 3:
    type = Type(BaseType::_string);
    break;
case 4:
    type = Type(BaseType::_boolean);
    break;
case 5:
    type = Type(BaseType::_boolean);
    break;
default:
    std::cerr << "Invalid way." << std::endl;
    break;
}

}
