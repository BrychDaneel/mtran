#include "paramsrule.h"

#include <rules/paramsstartrule.h>
#include <rules/paramsendrule.h>

ParamsRule* ParamsRule::instance;


ParamsRule::ParamsRule()
{
    std::vector<Rule*> var;
    var.push_back(ParamsStartRule::getInstance());
    var.push_back(ParamsEndRule::getInstance());
    vars.push_back(var);
}

ParamsRule *ParamsRule::getInstance()
{
    if (instance == nullptr){
        instance = new ParamsRule;
    }
    return instance;
}
