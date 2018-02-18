#include "exprrule.h"

#include <rules/exprstartrule.h>
#include <rules/exprendrule.h>

ExprRule* ExprRule::instance;


ExprRule::ExprRule()
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
    }
    return instance;
}

