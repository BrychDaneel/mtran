#include "sumstartrule.h"

#include <rules/factrule.h>

SumStartRule* SumStartRule::instance;


SumStartRule::SumStartRule()
{
    std::vector<Rule*> var;
    var.push_back(FactRule::getInstance());
    vars.push_back(var);
}

SumStartRule *SumStartRule::getInstance()
{
    if (instance == nullptr){
        instance = new SumStartRule;
    }
    return instance;
}
