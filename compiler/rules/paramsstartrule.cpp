#include "paramsstartrule.h"

#include <rules/exprrule.h>

ParamsStartRule* ParamsStartRule::instance;


void ParamsStartRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(ExprRule::getInstance());
    vars.push_back(var);
}

ParamsStartRule *ParamsStartRule::getInstance()
{
    if (instance == nullptr){
        instance = new ParamsStartRule;
        instance->setup();
    }
    return instance;
}
