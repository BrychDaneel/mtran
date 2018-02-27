#include "definenode.h"

#include <nodes/typenode.h>
#include <nodes/idlistnode.h>

#include <iostream>

#include <sstream>

DefineNode::DefineNode(SymbolTable *symbolTable, int way)
    : BaseNode(symbolTable, way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void DefineNode::semantic()
{
    if (way == 0)
        return;

    nodes[0]->semantic();
    nodes[2]->semantic();

    idList = dynamic_cast<IdListNode*>(nodes[0])->getIdList();
    type = dynamic_cast<TypeNode*>(nodes[2])->getType();

    for (int gid : idList)
        if (symbolTable->getInfo(gid) != nullptr &&
                symbolTable->isLocal() == symbolTable->getInfo(gid)->isLocal())
        {
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Double define" << std::endl;
            exit(1);
        } else
            symbolTable->define(gid, type);


    nodes[4]->semantic();
}

std::string DefineNode::getCode()
{
    std::stringstream buf;
    code = "";
    for (int id : idList){
        symbolTable->define(id, type);
        buf.str("");
        symbolTable->getInfo(id)->setAdress(symbolTable->getAdress());
        symbolTable->push(type.getSize());
        buf << "push " << type.getSize();
        emitCode(buf.str());
    }
    if (nodes[4]->getWay() != 0)
        code = code + nodes[4]->getCode();

    return code;
}
