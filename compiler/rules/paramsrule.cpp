#include "paramsrule.h"

#include <rules/exprrule.h>
#include <rules/paramsendrule.h>
#include <rules/emptyrule.h>

#include <nodes/paramsnode.h>

ParamsRule* ParamsRule::instance;


void ParamsRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);


    var.clear();
    var.push_back(ExprRule::getInstance());
    var.push_back(ParamsEndRule::getInstance());
    vars.push_back(var);
}

ParamsRule *ParamsRule::getInstance()
{
    if (instance == nullptr){
        instance = new ParamsRule;
        instance->setup();
    }
    return instance;
}

Node *ParamsRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new ParamsNode(symbolTable, way, false);
}
