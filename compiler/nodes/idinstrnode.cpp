#include "idinstrnode.h"

#include <nodes/terminalnode.h>
#include <tokens/idtoken.h>
#include <nodes/callnode.h>
#include <nodes/assignnode.h>

#include <iostream>

#include <nodes/paramsnode.h>

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
        }

        if (nodes[0]->getWay() != 0 && idinf->getType().isSimple() && idinf->getType().getBaseType() == BaseType::_string)
            dynamic_cast<AssignNode*>(nodes[1])->setRequiredType(BaseType::_char);
        else
            dynamic_cast<AssignNode*>(nodes[1])->setRequiredType(idinf->getType().getBaseType());

        nodes[1]->semantic();
        return;
    }

    if (symbolTable->getSignatyre(gid) == 0){
        std::cerr << "SEMANTIC ERROR(" << getLine() << "," << getPos() << "): Unknown function" << std::endl;
        exit(1);
    }


    dynamic_cast<CallNode*>(nodes[0])->setGID(gid);
    nodes[0]->semantic();

}
