#include "instrlistrule.h"

#include <rules/instrrule.h>
#include <rules/instrlistendrule.h>

InstrListRule* InstrListRule::instance;


void InstrListRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(InstrRule::getInstance());
    var.push_back(InstrListEndRule::getInstance());
    vars.push_back(var);
}

InstrListRule *InstrListRule::getInstance()
{
    if (instance == nullptr){
        instance = new InstrListRule;
        instance->setup();
    }
    return instance;
}
