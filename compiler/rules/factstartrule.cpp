#include "factstartrule.h"

#include <rules/operandrule.h>

FactStartRule* FactStartRule::instance;


void FactStartRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(OperandRule::getInstance());
    vars.push_back(var);
}

FactStartRule *FactStartRule::getInstance()
{
    if (instance == nullptr){
        instance = new FactStartRule;
        instance->setup();
    }
    return instance;
}
