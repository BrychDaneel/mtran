#include "functionnode.h"

#include <tokens/idtoken.h>
#include <nodes/terminalnode.h>
#include <nodes/signode.h>
#include <nodes/typenode.h>

#include <sstream>

#include <algorithm>

FunctionNode::FunctionNode(SymbolTable *symbolTable, int way, bool isProc)
{
    this->symbolTable = symbolTable;
    this->way = way;
    this->isProc = isProc;
}

void FunctionNode::semantic()
{

    gid = dynamic_cast<IdToken*>( dynamic_cast<TerminalNode*>(nodes[1])->getToken() )->getGID();

    nodes[3]->semantic();
    sig = dynamic_cast<SigNode*>(nodes[3])->getSig();
    paramsGID = dynamic_cast<SigNode*>(nodes[3])->getIdList();


    if (isProc)
        returnType = BaseType::_void;
    else{
        nodes[6]->semantic();
        returnType = dynamic_cast<TypeNode*>(nodes[6])->getType();
        funDif = 2;
    }

    sig.setResult(returnType);

    symbolTable->addFunction(gid, sig);
    symbolTable->startFunction(gid, paramsGID, returnType);

    for (size_t i=0; i<sig.getParams().size(); i++)
        symbolTable->define(paramsGID[i], sig.getParams()[i]);

    symbolTable->define(gid, returnType);

    nodes[funDif + 6]->semantic();
    nodes[funDif + 8]->semantic();

    symbolTable->endFunction();
}

std::string FunctionNode::getCode()
{
    code = "";
    std::stringstream buf;

    int funEnter = symbolTable->getLabel();
    int funEnd = symbolTable->getLabel();

    symbolTable->addCallLabel(gid, funEnter);

    buf.str("");
    buf << "jmp " << funEnd;
    emitCode(buf.str());

    buf.str("");
    buf << "label " << funEnter;
    emitCode(buf.str());


    symbolTable->startFunction(gid, paramsGID, returnType);

    for (size_t i=0; i<sig.getParams().size(); i++){
        int parAdr = symbolTable->getAdress();
        symbolTable->push(sig.getParams()[i].getSize());
        symbolTable->define(paramsGID[i], sig.getParams()[i]);
        symbolTable->getInfo(paramsGID[i])->setAdress(parAdr);
    }

    int retAdr = symbolTable->getAdress();
    symbolTable->push(returnType.getSize());
    symbolTable->define(gid, returnType);
    symbolTable->getInfo(gid)->setAdress(retAdr);

    symbolTable->push(2);

    code = code + nodes[funDif + 6]->getCode();
    code = code + nodes[funDif + 8]->getCode();

    for (IdInfo* info : symbolTable->getThisVisable()){
        int pgid = info->getGId();
        if (std::find(paramsGID.begin(), paramsGID.end(), pgid) == paramsGID.end() && pgid != gid){
            buf.str("");
            buf << "pop " << symbolTable->getInfo(pgid)->getType().getSize();
            emitCode(buf.str());
        }
    }

    symbolTable->endFunction();

    emitCode("ret");

    buf.str("");
    buf << "label " << funEnd;
    emitCode(buf.str());

    return code;
}
