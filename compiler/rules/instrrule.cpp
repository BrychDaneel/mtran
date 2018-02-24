#include "instrrule.h"

#include <rules/idinstrrule.h>
#include <rules/ifrule.h>
#include <rules/forrule.h>
#include <rules/whilerule.h>
#include <rules/repeatrule.h>
#include <rules/controlrule.h>

InstrRule* InstrRule::instance;


void InstrRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(IdInstrRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(IfRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(ForRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(WhileRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(RepeatRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(ControlRule::getInstance());
    vars.push_back(var);
}

InstrRule *InstrRule::getInstance()
{
    if (instance == nullptr){
        instance = new InstrRule;
        instance->setup();
    }
    return instance;
}
