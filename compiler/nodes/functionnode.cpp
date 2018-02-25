#include "functionnode.h"

#include <tokens/idtoken.h>
#include <nodes/terminalnode.h>
#include <nodes/signode.h>
#include <nodes/typenode.h>

FunctionNode::FunctionNode(SymbolTable *symbolTable, int way, bool isProc)
{
    this->symbolTable = symbolTable;
    this->way = way;
    this->isProc = isProc;
}

void FunctionNode::semantic()
{

    int gid = dynamic_cast<IdToken*>( dynamic_cast<TerminalNode*>(nodes[1])->getToken() )->getGID();

    nodes[3]->semantic();
    sig = dynamic_cast<SigNode*>(nodes[3])->getSig();
    paramsGID = dynamic_cast<SigNode*>(nodes[3])->getIdList();

    Type returnType;
    int funDif = 0;
    if (isProc)
        returnType = BaseType::_void;
    else{
        nodes[6]->semantic();
        returnType = dynamic_cast<TypeNode*>(nodes[6])->getType();
        funDif = 2;
    }

    sig.setResult(returnType);

    symbolTable->addFunction(gid, sig);
    symbolTable->startFunction(returnType);

    for (size_t i=0; i<sig.getParams().size(); i++)
        symbolTable->define(paramsGID[i], sig.getParams()[i]);

    symbolTable->define(gid, returnType);

    nodes[funDif + 6]->semantic();
    nodes[funDif + 8]->semantic();

    symbolTable->endFunction();
}
