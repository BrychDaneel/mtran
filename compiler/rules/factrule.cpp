#include "factrule.h"

#include <rules/factstartrule.h>
#include <rules/factendrule.h>

FactRule* FactRule::instance;


void FactRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(FactStartRule::getInstance());
    var.push_back(FactEndRule::getInstance());
    vars.push_back(var);
}

FactRule *FactRule::getInstance()
{
    if (instance == nullptr){
        instance = new FactRule;
        instance->setup();
    }
    return instance;
}
