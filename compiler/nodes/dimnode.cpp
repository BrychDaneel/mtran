#include "dimnode.h"

#include <nodes/rangenode.h>

DimNode::DimNode(SymbolTable *symbolTable, int way, bool first)
    : BaseNode(symbolTable, way)
{
    this->first = first;
}

void DimNode::semantic()
{
    if (!first && way == 0)
        return;

    int rangeIndex;
    int restIndex;

    if (first){
        rangeIndex = 0;
        restIndex = 1;
    } else{
        rangeIndex = 1;
        restIndex = 2;
    }

    nodes[rangeIndex]->semantic();
    RangeNode* rangeNode = dynamic_cast<RangeNode*>(nodes[rangeIndex]);
    start.push_back(rangeNode->getStart());
    dimSize.push_back(rangeNode->getEnd() - rangeNode->getStart());


    nodes[restIndex]->semantic();
    DimNode* dimNode = dynamic_cast<DimNode*>(nodes[restIndex]);
    for (int s : dimNode->getStart())
        start.push_back(s);
    for (int d : dimNode->getDimSize())
        dimSize.push_back(d);
}

std::vector<int> DimNode::getStart()
{
    return start;
}

std::vector<int> DimNode::getDimSize()
{
    return dimSize;
}
