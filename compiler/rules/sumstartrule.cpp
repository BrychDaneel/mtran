#include "sumstartrule.h"

#include <rules/factrule.h>

#include <nodes/emptyexprnode.h>

SumStartRule* SumStartRule::instance;


void SumStartRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(FactRule::getInstance());
    vars.push_back(var);
}

SumStartRule *SumStartRule::getInstance()
{
    if (instance == nullptr){
        instance = new SumStartRule;
        instance->setup();
    }
    return instance;
}

Node *SumStartRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new EmptyExprNode(symbolTable, way);
}
