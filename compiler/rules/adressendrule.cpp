#include "adressendrule.h"

#include <rules/emptyrule.h>
#include <rules/indexrule.h>

AdressEndRule* AdressEndRule::instance;


void AdressEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(IndexRule::getInstance());
    vars.push_back(var);
}

AdressEndRule *AdressEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new AdressEndRule;
        instance->setup();
    }
    return instance;
}
