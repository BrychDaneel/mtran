#include "sumrule.h"

#include <rules/sumstartrule.h>
#include <rules/sumendrule.h>


SumRule* SumRule::instance;


SumRule::SumRule()
{
    std::vector<Rule*> var;
    var.push_back(SumStartRule::getInstance());
    var.push_back(SumEndRule::getInstance());
    vars.push_back(var);
}

SumRule *SumRule::getInstance()
{
    if (instance == nullptr){
        instance = new SumRule;
    }
    return instance;
}
