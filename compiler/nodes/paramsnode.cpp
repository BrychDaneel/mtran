#include "paramsnode.h"

#include <nodes/virtualexprnode.h>
#include <typeconvertor.h>

#include <iostream>

ParamsNode::ParamsNode(SymbolTable *symbolTable, int way, bool midle)
{
    this->symbolTable = symbolTable;
    this->way = way;
    this->midle = midle;
}

void ParamsNode::semantic()
{
    if (way == 0){
        if (types.size() == 0)
            return;
        else{
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Not enough params" << std::endl;
            exit(1);
        }
    }

    if (midle){
        dynamic_cast<ParamsNode*>(nodes[1])->setTypes(types);
        return;
    }

    VirtualExprNode* exprNode = dynamic_cast<VirtualExprNode*>(nodes[0]);
    exprNode->semantic();

    Type commonType = TypeConvertor::getCommonType(types[0], exprNode->getType());
    if (!TypeConvertor::isEqual(commonType, types[0])){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Bad parametrs type" << std::endl;
        exit(1);
    }

    if (nodes[1]->getWay() == 0 && types.size() > 1){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Not enough params" << std::endl;
        exit(1);
    }

    if (nodes[1]->getWay() != 0 && types.size() == 1){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Too many params" << std::endl;
        exit(1);
    }

    std::vector<Type> restTypes = types;
    restTypes.erase(restTypes.begin());
    dynamic_cast<ParamsNode*>(nodes[1])->setTypes(restTypes);
    nodes[1]->semantic();
}

void ParamsNode::setTypes(std::vector<Type> types)
{
    this->types = types;
}
