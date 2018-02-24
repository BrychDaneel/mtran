#include "basenode.h"
#include <iostream>

BaseNode::BaseNode()
{

}

BaseNode::BaseNode(SymbolTable* symbolTable, int way)
{
    this->way = way;
    this->symbolTable = symbolTable;
}

void BaseNode::add(Node *node)
{
    nodes.push_back(node);
}

void BaseNode::print(int level)
{
    for (int i=0; i<level*2; i++)
        std::cout << " ";
    std::cout << getName() << std::endl;

    for (Node* node : nodes)
        node->print(level + 1);
}

void BaseNode::semantic()
{
    for (Node* node : nodes)
        node->semantic();
}

std::string BaseNode::getCode()
{
    code = "";
    return code;
}

void BaseNode::emitCode(std::string c)
{
    code = code + '\n' + c;
}

SymbolTable *BaseNode::getSymbolTable()
{
    return symbolTable;
}

int BaseNode::getWay()
{
    return way;
}

std::vector<Node *> BaseNode::getNodes()
{
    return nodes;
}

int BaseNode::getLine()
{
    return nodes[0]->getLine();
}

int BaseNode::getPos()
{
    return nodes[0]->getPos();
}
