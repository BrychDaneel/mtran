#include "fornode.h"


#include <nodes/terminalnode.h>
#include <tokens/idtoken.h>
#include <nodes/virtualexprnode.h>

#include <iostream>
#include <sstream>
#include <nodes/paramsnode.h>
#include <nodes/assignnode.h>
#include <nodes/indexnode.h>

ForNode::ForNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void ForNode::semantic()
{

    subType = SubType::var;

    gid = dynamic_cast<IdToken*>(dynamic_cast<TerminalNode*>(nodes[1])->getToken())->getGID();

    if (symbolTable->getInfo(gid) == nullptr){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Undefine var" << std::endl;
        exit(1);
    }

    IdInfo* idinf = symbolTable->getInfo(gid);

    if (idinf->getType().getBaseType() != BaseType::_integer){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): For index must be integer" << std::endl;
        exit(1);
    }

    if (nodes[2]->getWay() != 0 && idinf->getType().isSimple()){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): It is not array" << std::endl;
        exit(1);
    }

    if (nodes[2]->getWay() == 0 && !idinf->getType().isSimple()){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): You must select index" << std::endl;
        exit(1);
    }

    if (nodes[2]->getWay() != 0){
        subType = SubType::array;
        std::vector<Type> types;
        for (size_t i=0; i<idinf->getType().getDim().size(); i++)
            types.push_back(BaseType::_integer);
        dynamic_cast<ParamsNode*>(nodes[2]->getNodes()[0]->getNodes()[1])->setTypes(types);
        nodes[2]->semantic();
    }

    dynamic_cast<AssignNode*>(nodes[3])->setRequiredType(idinf->getType().getBaseType());
    nodes[3]->semantic();

    VirtualExprNode* endExpr = dynamic_cast<VirtualExprNode*>(nodes[5]);
    endExpr->semantic();

    if (endExpr->getType().getBaseType() != BaseType::_integer){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): For stop index must be integer" << std::endl;
        exit(1);
    }

    symbolTable->startLoop(0, 0, 0, 0);
    nodes[7]->semantic();
    symbolTable->endLoop();

    return;
}

std::string ForNode::getCode()
{
    code = "";
    std::stringstream buf;

    std::string strVarAdress;

    if (subType == SubType::var){
        IdInfo* info = symbolTable->getInfo(gid);
        dynamic_cast<AssignNode*>(nodes[3])->setAdress(info->getAdress(), info->isLocal(), false);
        code = code + nodes[3]->getCode();
        buf.str("");
        if (info->isLocal())
            buf << "$";
        else
            buf << "#";
        buf << info->getAdress();
        strVarAdress = buf.str();
    }
    if (subType == SubType::array){
        IdInfo* info = symbolTable->getInfo(gid);

        info = symbolTable->getInfo(gid);
        int adrAdr = symbolTable->getAdress();
        emitCode("push 1");
        symbolTable->push(1);
        buf.str("");
        buf << "load_i " << "$" << adrAdr << " " << info->getAdress();
        emitCode(buf.str());

        IndexNode* indNode = dynamic_cast<IndexNode*>(nodes[2]->getNodes()[0]);
        indNode->setDist(adrAdr, true);
        indNode->setType(info->getType());

        code = code + indNode->getCode();

        dynamic_cast<AssignNode*>(nodes[3])->setAdress(adrAdr, true, true);
        code = code + nodes[3]->getCode();

        buf.str("");
        buf << "?$" << adrAdr;
        strVarAdress = buf.str();
    }

    int loopStart = symbolTable->getLabel();
    int loopEnd = symbolTable->getLabel();
    int loopContinue = loopStart;

    int stopExprAdress = symbolTable->getAdress();
    emitCode("push 1");
    symbolTable->push(1);

    int boolAdress = symbolTable->getAdress();
    emitCode("push 1");
    symbolTable->push(1);

    int oneAdress = symbolTable->getAdress();
    emitCode("push 1");
    symbolTable->push(1);
    buf.str("");
    buf << "load_i $" << oneAdress << " " << 1;
    emitCode(buf.str());


    VirtualExprNode* endExpr = dynamic_cast<VirtualExprNode*>(nodes[5]);
    endExpr->setDist(stopExprAdress, true);
    code = code + endExpr->getCode();

    buf.str("");
    buf << "label " << loopStart;
    emitCode(buf.str());

    buf.str("");
    buf << "ica $" << boolAdress << " ";
    buf << strVarAdress;
    buf << " ";
    buf << "$" << stopExprAdress;
    emitCode(buf.str());

    buf.str("");
    buf << "jt " << loopEnd << " $" << boolAdress;
    emitCode(buf.str());

    symbolTable->startLoop(loopStart, loopEnd, loopContinue, symbolTable->getAdress());
    code = code + nodes[7]->getCode();
    symbolTable->endLoop();

    buf.str("");
    buf << "iadd " << strVarAdress << " " << strVarAdress << " $" << oneAdress;
    emitCode(buf.str());

    buf.str("");
    buf << "jmp " << loopContinue;
    emitCode(buf.str());

    buf.str("");
    buf << "label " << loopEnd;
    emitCode(buf.str());

    emitCode("pop 1");
    symbolTable->pop(1);
    emitCode("pop 1");
    symbolTable->pop(1);
    emitCode("pop 1");
    symbolTable->pop(1);


    if (subType == SubType::array){
        emitCode("pop 1");
        symbolTable->pop(1);
    }

    return code;
}
