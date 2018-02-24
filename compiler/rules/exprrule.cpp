#include "exprrule.h"

#include <rules/exprstartrule.h>
#include <rules/exprendrule.h>

#include <nodes/binarnode.h>

ExprRule* ExprRule::instance;


void ExprRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(ExprStartRule::getInstance());
    var.push_back(ExprEndRule::getInstance());
    vars.push_back(var);
}

ExprRule *ExprRule::getInstance()
{
    if (instance == nullptr){
        instance = new ExprRule;
        instance->setup();
    }
    return instance;
}

Node *ExprRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new BinarNode(symbolTable, way, true);
}

