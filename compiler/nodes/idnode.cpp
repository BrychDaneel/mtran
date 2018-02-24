#include "idnode.h"
#include <nodes/terminalnode.h>
#include <tokens/idtoken.h>

IdNode::IdNode(SymbolTable *symbolTable, int way)
 : BaseNode(symbolTable, way)
{

}

void IdNode::semantic()
{
    TerminalNode* node = dynamic_cast<TerminalNode*>(nodes[0]);
    IdToken* token = dynamic_cast<IdToken*>(node->getToken());
    gid = token->getGID();
}

int IdNode::getGID()
{
    return gid;
}

