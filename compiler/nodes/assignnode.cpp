#include "assignnode.h"

#include <typeconvertor.h>
#include <nodes/virtualexprnode.h>
#include <iostream>

#include <sstream>

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

void AssignNode::setAdress(int adress, bool isLocal, bool isRel)
{
    this->adress = adress;
    this->isLocal = isLocal;
    this->isRel = isRel;
}

std::string AssignNode::getCode()
{
    code = "";
    std::stringstream buf;

    buf << "push " << requiredType.getSize();
    emitCode(buf.str());
    int distAdress = symbolTable->getAdress();
    symbolTable->push(requiredType.getSize());

    dynamic_cast<VirtualExprNode*>(nodes[1])->setDist(distAdress, true);
    code = code + nodes[1]->getCode();

    buf.str("");
    buf << "mov " << requiredType.getSize() << " ";
    if (isRel)
        buf << "?";
    if (isLocal)
        buf << "$";
    else
        buf << "#";
    buf << adress << " ";

    buf << "$" << distAdress;
    emitCode(buf.str());

    buf.str("");
    buf << "pop " << requiredType.getSize();
    emitCode(buf.str());
    symbolTable->pop(requiredType.getSize());

    return code;
}
