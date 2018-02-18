#include "factendrule.h"

#include <rules/emptyrule.h>
#include <rules/multioprule.h>
#include <rules/factrule.h>

FactEndRule* FactEndRule::instance;


void FactEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(MultiOpRule::getInstance());
    var.push_back(FactRule::getInstance());
    vars.push_back(var);
}

FactEndRule *FactEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new FactEndRule;
        instance->setup();
    }
    return instance;
}
