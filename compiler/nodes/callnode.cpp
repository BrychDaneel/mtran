#include "callnode.h"

#include <nodes/paramsnode.h>
#include <iostream>
#include <sstream>

CallNode::CallNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void CallNode::semantic()
{
    ParamsNode* paramsNode = dynamic_cast<ParamsNode*>(nodes[1]);

    if (isUser){
        paramsTypes = symbolTable->getSignatyre(gid)->getParams();
        paramsNode->setTypes(paramsTypes);
        nodes[1]->semantic();
        return;
    }

    fun = symbolTable->getBuidIn(gid);
    paramsNode->setBuildIn(true);
    paramsNode->semantic();

    paramsTypes = paramsNode->getTypes();

    if (!fun->canAccept(paramsTypes)){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Bad parametrs types" << std::endl;
        exit(1);
    }
}

void CallNode::setGID(int gid)
{
    this->gid = gid;

    isUser = symbolTable->getSignatyre(gid) != nullptr;

    if (!isUser && symbolTable->getBuidIn(gid) == nullptr){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Unknown function" << std::endl;
        exit(1);
    }


}

Type CallNode::getRetType(){
    if (isUser)
        return symbolTable->getSignatyre(gid)->getResult();

    return symbolTable->getBuidIn(gid)->getRetType();
}

std::string CallNode::getCode()
{
    code = "";
    std::vector<int> adressList;
    std::vector<bool> isLocalList;
    Type retType = getRetType();
    int callSize = 0;
    std::stringstream buf;

    for (Type type : paramsTypes){
        buf.str("");
        buf << "push ";
        buf << type.getSize();
        emitCode(buf.str());
        adressList.push_back(symbolTable->getAdress());
        symbolTable->push(type.getSize());
        callSize += type.getSize();
        isLocalList.push_back(true);
    }

    dynamic_cast<ParamsNode*>(nodes[1])->setDistList(adressList, isLocalList);
    code = code + nodes[1]->getCode();

    buf.str("");
    buf << "push ";
    buf << retType.getSize();
    emitCode(buf.str());
    int retAdress = symbolTable->getAdress();
    symbolTable->push(retType.getSize());
    callSize += retType.getSize();

    if (!isUser)
        code = code + fun->call(paramsTypes, adressList, isLocalList, retAdress, true);
    else{
        buf.str("");
        buf << "call " << callSize << " " << symbolTable->getCallLabel(gid);
        emitCode(buf.str());
    }

    if (destAdress != -1){
        buf.str("");
        buf << "mov " << retType.getSize() << " ";
        if (destIsLocal)
            buf << "$";
        else
            buf << "#";
        buf << destAdress;
        buf << " $" << retAdress;
        emitCode(buf.str());
    }


    buf.str("");
    buf << "pop ";
    buf << retType.getSize();
    emitCode(buf.str());
    symbolTable->pop(retType.getSize());

    for (Type type : paramsTypes){
        std::stringstream buf;
        buf << "pop ";
        buf << type.getSize();
        emitCode(buf.str());
        symbolTable->pop(type.getSize());
    }

    return code;
}

void CallNode::setDist(int dist, bool isLocal)
{
    destAdress = dist;
    this->destIsLocal = isLocal;
}
