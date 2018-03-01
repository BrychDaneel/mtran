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

void BaseNode::printTypes(int level)
{
    for (int i=0; i<level*2; i++)
        std::cout << " ";
    std::cout << getName() << std::endl;

    for (Node* node : nodes)
        node->printTypes(level + 1);
}

void BaseNode::semantic()
{
    for (Node* node : nodes)
        node->semantic();
}

std::string BaseNode::getCode()
{
    code = "";
    for (size_t i=0; i<nodes.size(); i++)
        code = code + nodes[i]->getCode();
    return code;
}

void BaseNode::emitCode(std::string c)
{
    code = code + c + '\n';
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
    if (nodes.size() == 0)
        return -1;
    size_t i = 0;
    int result = - 1;
    do
        result = nodes[i++]->getLine();
    while (result == -1  && i<nodes.size());

    return result;
}

int BaseNode::getPos()
{
    if (nodes.size() == 0)
        return -1;

    size_t i = 0;
    int result = -1;
    do
        result = nodes[i++]->getPos();
    while (result == -1 && i<nodes.size());

    return result;
}
