#include "sumendrule.h"

#include <rules/sumoprule.h>
#include <rules/sumrule.h>
#include <rules/emptyrule.h>

SumEndRule* SumEndRule::instance;


SumEndRule::SumEndRule()
{
    std::vector<Rule*> var;
    var.push_back(SumOpRule::getInstance());
    var.push_back(SumRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);
}

SumEndRule *SumEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new SumEndRule;
    }
    return instance;
}
