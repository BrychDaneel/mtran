#include "rangenode.h"
#include <nodes/terminalnode.h>
#include <tokens/integertoken.h>

RangeNode::RangeNode(SymbolTable *symbolTable, int way)
    : BaseNode(symbolTable, way)
{

}

void RangeNode::semantic()
{
    IntegerToken* stoken = dynamic_cast<IntegerToken*>(dynamic_cast<TerminalNode*>(nodes[0])->getToken() );
    start = stoken->getValue();

    IntegerToken* etoken = dynamic_cast<IntegerToken*>(dynamic_cast<TerminalNode*>(nodes[2])->getToken() );
    end = etoken->getValue();
}

int RangeNode::getStart()
{
    return start;
}

int RangeNode::getEnd()
{
    return end;
}
