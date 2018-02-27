#include "ifnode.h"

#include <nodes/virtualexprnode.h>
#include <iostream>
#include <sstream>

IfNode::IfNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void IfNode::semantic()
{
    nodes[1]->semantic();
    Type type = dynamic_cast<VirtualExprNode*>(nodes[1])->getType();
    if (!type.isSimple() || type.getBaseType() != BaseType::_boolean){
        std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Condition must be boolean" << std::endl;
        exit(1);
    }
    nodes[3]->semantic();
    nodes[4]->semantic();
}

std::string IfNode::getCode()
{
    code = "";
    std::stringstream buf;

    int ifFalse = symbolTable->getLabel();
    int ifEnd = symbolTable->getLabel();

    int exprAdress = symbolTable->getAdress();
    emitCode("push 1");
    symbolTable->push(1);

    VirtualExprNode* expNode = dynamic_cast<VirtualExprNode*>(nodes[1]);
    expNode->setDist(exprAdress, true);
    code = code + expNode->getCode();

    buf.str("");
    buf << "jf " << ifFalse << " $" << exprAdress;
    emitCode(buf.str());

    code = code + nodes[3]->getCode();

    buf.str("");
    buf << "jmp " << ifEnd;
    emitCode(buf.str());

    buf.str("");
    buf << "label " << ifFalse;
    emitCode(buf.str());

    code = code + nodes[4]->getCode();

    buf.str("");
    buf << "label " << ifEnd;
    emitCode(buf.str());

    emitCode("pop 1");
    symbolTable->pop(1);

    return code;
}
