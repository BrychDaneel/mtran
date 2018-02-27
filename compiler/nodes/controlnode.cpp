#include "controlnode.h"

#include <typeconvertor.h>
#include <nodes/virtualexprnode.h>
#include <iostream>
#include <sstream>
#include <algorithm>

ControlNode::ControlNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void ControlNode::semantic()
{

    if (way == 0){
        int start, end, cont, adr;
        symbolTable->getLoopInfo(start, end, cont, adr);
        if (start == -1){
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Break outside Loop" << std::endl;
            exit(1);
        }
        return;
    }

    if (way == 1){
        int start, end, cont, adr;
        symbolTable->getLoopInfo(start, end, cont, adr);
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
        if ( !TypeConvertor::isEqual(commonType, type) ){
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Invalid returned type" << std::endl;
            exit(1);
        }
        return;
    }



}

std::string ControlNode::getCode()
{
    code = "";
    std::stringstream buf;

    if (way == 0){
        int loopStart, loopEnd, loopContinue, adr;
        symbolTable->getLoopInfo(loopStart, loopEnd, loopContinue, adr);

        buf.str("");
        buf << "pop " << symbolTable->getAdress() - adr;
        emitCode(buf.str());

        buf.str("");
        buf << "jmp" << " ";
        buf << loopEnd;
        emitCode(buf.str());
    }
    if (way == 1){
        int loopStart, loopEnd, loopContinue, adr;
        symbolTable->getLoopInfo(loopStart, loopEnd, loopContinue, adr);

        buf.str("");
        buf << "pop " << symbolTable->getAdress() - adr;
        emitCode(buf.str());

        buf.str("");
        buf << "jmp" << " ";
        buf << loopContinue;
        emitCode(buf.str());
    }
    if (way == 2){
        int gid = symbolTable->getFunGID();
        IdInfo* info = symbolTable->getInfo(gid);
        if (info->getType().getBaseType() != BaseType::_void){
            VirtualExprNode* expr = dynamic_cast<VirtualExprNode*>(nodes[2]);
            expr->setDist(info->getAdress(), info->isLocal());
            code = code + expr->getCode();
        }

        int callSize = symbolTable->getSignatyre(gid)->getSize();
        callSize += 2;

        int ds = symbolTable->getAdress() - callSize;
        buf.str("");
        buf << "pop ";
        buf << ds;
        emitCode(buf.str());

        buf.str("");
        buf << "ret";
        emitCode(buf.str());
    }
    return code;
}
