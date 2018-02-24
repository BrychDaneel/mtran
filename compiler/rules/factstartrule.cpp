#include "factstartrule.h"

#include <rules/operandrule.h>


#include <nodes/emptyexprnode.h>

FactStartRule* FactStartRule::instance;


void FactStartRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(OperandRule::getInstance());
    vars.push_back(var);
}

FactStartRule *FactStartRule::getInstance()
{
    if (instance == nullptr){
        instance = new FactStartRule;
        instance->setup();
    }
    return instance;
}

Node *FactStartRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new EmptyExprNode(symbolTable, way);
}
