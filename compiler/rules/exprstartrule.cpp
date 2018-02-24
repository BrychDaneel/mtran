#include "exprstartrule.h"

#include <rules/sumrule.h>

#include <nodes/emptyexprnode.h>

ExprStartRule* ExprStartRule::instance;


void ExprStartRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(SumRule::getInstance());
    vars.push_back(var);
}

ExprStartRule *ExprStartRule::getInstance()
{
    if (instance == nullptr){
        instance = new ExprStartRule;
        instance->setup();
    }
    return instance;
}

Node *ExprStartRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new EmptyExprNode(symbolTable, way);
}
