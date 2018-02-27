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

    if (buildIn){
        if (way == 0)
            return;

        ParamsNode* paramsNode = dynamic_cast<ParamsNode*>(nodes[1]);
        paramsNode->setBuildIn(true);

        if (midle){
            paramsNode->semantic();
            types = paramsNode->getTypes();
            return;
        }

        VirtualExprNode* exprNode = dynamic_cast<VirtualExprNode*>(nodes[0]);
        exprNode->semantic();
        types.push_back(exprNode->getType());

        paramsNode->semantic();
        for (Type type : paramsNode->getTypes())
            types.push_back(type);

        return;
    }

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
    ParamsNode* paramsNode = dynamic_cast<ParamsNode*>(nodes[1]);
    paramsNode->setTypes(restTypes);
    nodes[1]->semantic();
}

void ParamsNode::setTypes(std::vector<Type> types)
{
    this->types = types;
}

void ParamsNode::setBuildIn(bool isBuildIn)
{
    this->buildIn = isBuildIn;
}

std::vector<Type> ParamsNode::getTypes()
{
    return types;
}

void ParamsNode::setDistList(std::vector<int> distList, std::vector<bool> isLocalList)
{
    this->distList = distList;
    this->isLocalList = isLocalList;
}


std::string ParamsNode::getCode()
{
    code = "";
    if (way == 0)
        return code;

    ParamsNode* paramsNode = dynamic_cast<ParamsNode*>(nodes[1]);
    if (midle){
        paramsNode->setDistList(distList, isLocalList);
        return paramsNode->getCode();
    }

    int dist = distList[0];
    bool isLocal = isLocalList[0];
    distList.erase(distList.begin());
    paramsNode->setDistList(distList, isLocalList);

    VirtualExprNode* exprNode = dynamic_cast<VirtualExprNode*>(nodes[0]);
    exprNode->setDist(dist, isLocal);
    code = code + exprNode->getCode();

    paramsNode->setDistList(distList, isLocalList);
    code = code + paramsNode->getCode();

    return code;
}
