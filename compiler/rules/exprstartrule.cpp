#include "exprstartrule.h"

#include <rules/sumrule.h>

ExprStartRule* ExprStartRule::instance;


ExprStartRule::ExprStartRule()
{
    std::vector<Rule*> var;
    var.push_back(SumRule::getInstance());
    vars.push_back(var);
}

ExprStartRule *ExprStartRule::getInstance()
{
    if (instance == nullptr){
        instance = new ExprStartRule;
    }
    return instance;
}
