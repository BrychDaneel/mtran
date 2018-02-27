#include "whilenode.h"

#include <nodes/virtualexprnode.h>
#include <iostream>
#include <sstream>

WhileNode::WhileNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void WhileNode::semantic()
{   
    nodes[1]->semantic();
    Type type = dynamic_cast<VirtualExprNode*>(nodes[1])->getType();
    if (!type.isSimple() || type.getBaseType() != BaseType::_boolean){
        std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Condition must be boolean" << std::endl;
        exit(1);
    }
    symbolTable->startLoop(0, 0, 0, 0);
    nodes[3]->semantic();
    symbolTable->endLoop();
}

std::string WhileNode::getCode()
{
    code = "";
    std::stringstream buf;

    int loopStart = symbolTable->getLabel();
    int loopEnd = symbolTable->getLabel();
    int loopContinue = loopStart;

    buf.str("");
    buf << "label " << loopStart;
    emitCode(buf.str());

    int exprAdress = symbolTable->getAdress();
    emitCode("push 1");
    symbolTable->push(1);

    VirtualExprNode* expNode = dynamic_cast<VirtualExprNode*>(nodes[1]);
    expNode->setDist(exprAdress, true);
    code = code + expNode->getCode();

    buf.str("");
    buf << "jf " << loopEnd << " $" << exprAdress;
    emitCode(buf.str());

    symbolTable->startLoop(loopStart, loopEnd, loopContinue, symbolTable->getAdress());
    code = code + nodes[3]->getCode();
    symbolTable->endLoop();

    buf.str("");
    buf << "jmp " << loopStart;
    emitCode(buf.str());

    buf.str("");
    buf << "label " << loopEnd;
    emitCode(buf.str());

    emitCode("pop 1");
    symbolTable->pop(1);

    return code;
}
