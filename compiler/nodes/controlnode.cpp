#include "controlnode.h"

#include <typeconvertor.h>
#include <nodes/virtualexprnode.h>
#include <iostream>

ControlNode::ControlNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void ControlNode::semantic()
{

    if (way == 0){
        int start, end, cont;
        symbolTable->getLoopInfo(start, end, cont);
        if (start == -1){
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Break outside Loop" << std::endl;
            exit(1);
        }
        return;
    }

    if (way == 1){
        int start, end, cont;
        symbolTable->getLoopInfo(start, end, cont);
        if (start == -1){
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Continue outside Loop" << std::endl;
            exit(1);
        }
        return;
    }

    if (way == 2){
        Type type = symbolTable->getReturnType();
        VirtualExprNode* expr = dynamic_cast<VirtualExprNode*>(nodes[2]);
        expr->semantic();
        Type commonType = TypeConvertor::getCommonType(type, expr->getType());
        if ( TypeConvertor::isEqual(commonType, type) ){
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Invalid returned type" << std::endl;
            exit(1);
        }
        return;
    }



}
