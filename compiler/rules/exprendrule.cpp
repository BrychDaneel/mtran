#include "exprendrule.h"

#include <rules/sumrule.h>
#include <rules/sumoprule.h>
#include <tokens/eqtoken.h>
#include <rules/emptyrule.h>

ExprEndRule* ExprEndRule::instance;


ExprEndRule::ExprEndRule()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(SumOpRule::getInstance());
    var.push_back(SumRule::getInstance());
    vars.push_back(var);
}

ExprEndRule *ExprEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new ExprEndRule;
    }
    return instance;
}
