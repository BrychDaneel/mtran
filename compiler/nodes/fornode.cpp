#include "fornode.h"


#include <nodes/terminalnode.h>
#include <tokens/idtoken.h>
#include <nodes/virtualexprnode.h>

#include <iostream>
#include <nodes/paramsnode.h>
#include <nodes/assignnode.h>

ForNode::ForNode(SymbolTable *symbolTable, int way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void ForNode::semantic()
{

    int gid = dynamic_cast<IdToken*>(dynamic_cast<TerminalNode*>(nodes[1])->getToken())->getGID();

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

    nodes[7]->semantic();

    return;
}
