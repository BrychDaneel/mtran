#include "operandrule.h"

#include <rules/ynooprule.h>
#include <rules/varrule.h>

#include <nodes/emptyexprnode.h>
#include <nodes/unarnode.h>

OperandRule* OperandRule::instance;


void OperandRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(YnoOpRule::getInstance());
    var.push_back(OperandRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(VarRule::getInstance());
    vars.push_back(var);
}

OperandRule *OperandRule::getInstance()
{
    if (instance == nullptr){
        instance = new OperandRule;
        instance->setup();
    }
    return instance;
}

Node *OperandRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    if (way == 1)
        return new EmptyExprNode(symbolTable, way);

    return new UnarNode(symbolTable, way);
}
