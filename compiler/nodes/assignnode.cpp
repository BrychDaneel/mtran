#include "assignnode.h"

#include <typeconvertor.h>
#include <nodes/virtualexprnode.h>
#include <iostream>

AssignNode::AssignNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void AssignNode::semantic()
{
    VirtualExprNode* expr = dynamic_cast<VirtualExprNode*>(nodes[1]);
    expr->semantic();
    Type commonType =  TypeConvertor::getCommonType(expr->getType(), requiredType);
    if (!TypeConvertor::isEqual(commonType, requiredType)){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Bad expression type" << std::endl;
        exit(1);
    }
}

void AssignNode::setRequiredType(Type requiredType)
{
    this->requiredType = requiredType;
}
