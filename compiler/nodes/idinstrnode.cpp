#include "idinstrnode.h"

#include <nodes/terminalnode.h>
#include <tokens/idtoken.h>
#include <nodes/callnode.h>
#include <nodes/assignnode.h>

#include <iostream>
#include <sstream>

#include <nodes/paramsnode.h>
#include <nodes/indexnode.h>
#include <nodes/virtualexprnode.h>

IdInstrNode::IdInstrNode(SymbolTable *symbolTable, int way, bool start)
{
    this->symbolTable = symbolTable;
    this->way = way;
    this->start = start;
}

void IdInstrNode::setGID(int gid)
{
    this->gid = gid;
}

void IdInstrNode::semantic()
{
    if (start){
        TerminalNode* tnode = dynamic_cast<TerminalNode*>(nodes[0]);
        int gid = dynamic_cast<IdToken*>(tnode->getToken())->getGID();
        dynamic_cast<IdInstrNode*>(nodes[1])->setGID(gid);
        nodes[1]->semantic();
        return;
    }

    if (way == 0){

        subType = SubType::var;

        if (symbolTable->getInfo(gid) == nullptr){
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Undefine var" << std::endl;
            exit(1);
        }

        IdInfo* idinf = symbolTable->getInfo(gid);

        if (nodes[0]->getWay() != 0 && idinf->getType().isSimple() && idinf->getType().getBaseType() != BaseType::_string){
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): It is not array" << std::endl;
            exit(1);
        }

        if (nodes[0]->getWay() == 0 && !idinf->getType().isSimple()){
            std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): You must select index" << std::endl;
            exit(1);
        }

        if (nodes[0]->getWay() != 0){
            std::vector<Type> types;

            if (idinf->getType().isSimple() && idinf->getType().getBaseType() == BaseType::_string)
                types.push_back(BaseType::_integer);
            else
                for (size_t i=0; i<idinf->getType().getDim().size(); i++)
                    types.push_back(BaseType::_integer);
            dynamic_cast<ParamsNode*>(nodes[0]->getNodes()[0]->getNodes()[1])->setTypes(types);
            nodes[0]->semantic();
            subType = SubType::array;
        }

        if (nodes[0]->getWay() != 0 && idinf->getType().isSimple() && idinf->getType().getBaseType() == BaseType::_string){
            dynamic_cast<AssignNode*>(nodes[1])->setRequiredType(BaseType::_char);
            subType = SubType::string;
        }
        else
            dynamic_cast<AssignNode*>(nodes[1])->setRequiredType(idinf->getType().getBaseType());

        nodes[1]->semantic();
        return;
    }


    dynamic_cast<CallNode*>(nodes[0])->setGID(gid);
    nodes[0]->semantic();
    subType = SubType::fun;
}

std::string IdInstrNode::getCode()
{
    std::stringstream buf;
    if (start)
        return nodes[1]->getCode();

    code = "";
    if (subType == SubType::fun)
        return nodes[0]->getCode();
    if (subType == SubType::var){
        IdInfo* info = symbolTable->getInfo(gid);
        dynamic_cast<AssignNode*>(nodes[1])->setAdress(info->getAdress(), info->isLocal(), false);
        return nodes[1]->getCode();
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

        IndexNode* indNode = dynamic_cast<IndexNode*>(nodes[0]->getNodes()[0]);
        indNode->setDist(adrAdr, true);
        indNode->setType(info->getType());

        code = code + indNode->getCode();

        dynamic_cast<AssignNode*>(nodes[1])->setAdress(adrAdr, true, true);
        code = code + nodes[1]->getCode();

        emitCode("pop 1");
        symbolTable->pop(1);
    }

    if (subType == SubType::string){

        int valueAdr = symbolTable->getAdress();
        emitCode("push 1");
        symbolTable->push(1);
        buf.str("");

        VirtualExprNode* exprNode = dynamic_cast<VirtualExprNode*>(nodes[1]->getNodes()[1]);
        exprNode->setDist(valueAdr, true);
        code = code + exprNode->getCode();

        IdInfo* info = symbolTable->getInfo(gid);

        info = symbolTable->getInfo(gid);
        int adrAdr = symbolTable->getAdress();
        emitCode("push 1");
        symbolTable->push(1);
        buf.str("");
        buf << "load_i " << "$" << adrAdr << " " << 0;
        emitCode(buf.str());

        IndexNode* indNode = dynamic_cast<IndexNode*>(nodes[0]->getNodes()[0]);
        indNode->setDist(adrAdr, true);
        indNode->setType(Type(BaseType::_char, {1}, {256}));

        code = code + indNode->getCode();

        buf.str("");
        buf << "mov_to_s ";
        if (info->isLocal())
            buf << "$";
        else
            buf << "#";
        buf << info->getAdress() << " ";

        buf << "$" << valueAdr << " ";

        buf << "?$" << adrAdr;
        emitCode(buf.str());


        emitCode("pop 1");
        symbolTable->pop(1);

        emitCode("pop 1");
        symbolTable->pop(1);
    }

    return code;
}
