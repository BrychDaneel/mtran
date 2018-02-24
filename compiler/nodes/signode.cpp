#include "signode.h"

#include <nodes/idlistnode.h>
#include <nodes/typenode.h>
#include <nodes/typenode.h>

SigNode::SigNode(SymbolTable *symbolTable, int way, bool first)
{
    this->symbolTable = symbolTable;
    this->way = way;
    this->first = first;
}

void SigNode::semantic()
{
    if (first && way == 0)
        return;

    int st=0;
    if (!first)
        st = 1;


    Type type = dynamic_cast<TypeNode*>(nodes[st + 2])->getType();
    for (int gid : dynamic_cast<IdListNode*>(nodes[st + 0])->getIdList()){
        idList.push_back(gid);
        sig.addParam(type);
    }

    if (nodes[st + 3]->getWay() == 0)
        return;

    nodes[st + 3]->semantic();

    for (int gid : dynamic_cast<SigNode*>(nodes[st + 3])->getIdList())
        idList.push_back(gid);
    for (Type t : dynamic_cast<SigNode*>(nodes[st + 3])->getSig().getParams())
        sig.addParam(t);

}

Signature SigNode::getSig()
{
    return sig;
}

std::vector<int> SigNode::getIdList()
{
    return idList;
}
