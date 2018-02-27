#include "repeatnode.h"

#include <nodes/virtualexprnode.h>
#include <iostream>
#include <sstream>

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
    symbolTable->startLoop(0, 0, 0, 0);
    nodes[1]->semantic();
    symbolTable->endLoop();
}

std::string RepeatNode::getCode()
{
    code = "";
    std::stringstream buf;

    int loopStart = symbolTable->getLabel();
    int loopEnd = symbolTable->getLabel();
    int loopContinue = symbolTable->getLabel();

    int exprAdress = symbolTable->getAdress();
    emitCode("push 1");
    symbolTable->push(1);

    buf.str("");
    buf << "label " << loopStart;
    emitCode(buf.str());

    symbolTable->startLoop(loopStart, loopEnd, loopContinue, symbolTable->getAdress());
    code = code + nodes[1]->getCode();
    symbolTable->endLoop();

    buf.str("");
    buf << "label " << loopContinue;
    emitCode(buf.str());

    VirtualExprNode* expNode = dynamic_cast<VirtualExprNode*>(nodes[3]);
    expNode->setDist(exprAdress, true);
    code = code + expNode->getCode();

    buf.str("");
    buf << "jf " << loopStart << " $" << exprAdress;
    emitCode(buf.str());

    buf.str("");
    buf << "label " << loopEnd;
    emitCode(buf.str());

    emitCode("pop 1");
    symbolTable->pop(1);

    return code;
}
