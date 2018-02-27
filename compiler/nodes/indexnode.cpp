#include "indexnode.h"

#include <nodes/paramsnode.h>
#include <sstream>

IndexNode::IndexNode(SymbolTable *symbolTable, int way)
    : BaseNode(symbolTable, way)
{

}

void IndexNode::setDist(int adress, bool isLocal)
{
    this->adress = adress;
    this->isLocal = isLocal;
}

void IndexNode::setType(Type type)
{
    this->type = type;
}

std::string IndexNode::getCode()
{
    code = "";
    std::stringstream buf;

    std::vector<int> adressList;
    std::vector<bool> isLocalList;

    for (size_t i=0; i<type.getDim().size(); i++){
        std::stringstream buf;
        emitCode("push 1");
        adressList.push_back(symbolTable->getAdress());
        symbolTable->push(1);
        isLocalList.push_back(true);
    }

    dynamic_cast<ParamsNode*>(nodes[1])->setDistList(adressList, isLocalList);
    code = code + nodes[1]->getCode();

    int tempAdr = symbolTable->getAdress();
    emitCode("push 1");
    symbolTable->push(1);

    for (size_t i=0; i<type.getDim().size(); i++){
        buf.str("");
        buf << "load_i $" << tempAdr << " " << type.getStart()[i];
        emitCode(buf.str());

        buf.str("");
        buf << "isub $" << adressList[i] << " $" << adressList[i] << " $" << tempAdr;
        emitCode(buf.str());
    }

    int baseSize = Type(type.getBaseType()).getSize();
    int sz = baseSize;
    for (int i=type.getDim().size()-1; i>=0; i--){
        buf.str("");
        buf << "load_i $" << tempAdr << " " << sz;
        emitCode(buf.str());

        buf.str("");
        buf << "imull $" << adressList[i] << " $" << adressList[i] << " $" << tempAdr;
        emitCode(buf.str());

        sz *= type.getDim()[i];
    }


    emitCode("pop 1");
    symbolTable->pop(1);

    buf.str("");
    if (isLocal)
        buf << "$";
    else
        buf << "#";
    buf << adress;
    std::string sDistAdr = buf.str();

    for (size_t i=0; i<type.getDim().size(); i++){
        buf.str("");
        buf << "iadd " << sDistAdr << " " << sDistAdr << " $" << adressList[i];
        emitCode(buf.str());
    }

    buf.str("");
    buf << "pop ";
    buf << type.getDim().size();
    emitCode(buf.str());
    symbolTable->pop(type.getDim().size());

    return code;
}
