#include "operandrule.h"

#include <rules/ynooprule.h>
#include <rules/varrule.h>

OperandRule* OperandRule::instance;


OperandRule::OperandRule()
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
    }
    return instance;
}
