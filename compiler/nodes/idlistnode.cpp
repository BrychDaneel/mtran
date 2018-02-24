#include "idlistnode.h"

#include <nodes/terminalnode.h>
#include <tokens/idtoken.h>

IdListNode::IdListNode(SymbolTable *symbolTable, int way, bool first)
 : BaseNode(symbolTable, way)
{
    this->first = first;
}

void IdListNode::semantic()
{
    if (!first && way == 0)
        return;

    int idNodeIndex;
    int restNodeIndex;
    if (first){
        idNodeIndex = 0;
        restNodeIndex = 1;
    } else {
        idNodeIndex = 1;
        restNodeIndex = 2;
    }

    TerminalNode* node = dynamic_cast<TerminalNode*>(nodes[idNodeIndex]);
    IdToken* token = dynamic_cast<IdToken*>(node->getToken());
    idList.push_back(token->getGID());

    nodes[restNodeIndex]->semantic();
    IdListNode* restNode = dynamic_cast<IdListNode*>(nodes[restNodeIndex]);
    for (int gid : restNode->getIdList())
        idList.push_back(gid);

}

std::vector<int> IdListNode::getIdList()
{
    return idList;
}
