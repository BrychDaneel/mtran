#include "idinstrrule.h"

#include <rules/terminalrule.h>
#include <tokens/idtoken.h>
#include <rules/idinstrendrule.h>

IdInstrRule* IdInstrRule::instance;


void IdInstrRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    var.push_back(IdInstrEndRule::getInstance());
    vars.push_back(var);
}

IdInstrRule *IdInstrRule::getInstance()
{
    if (instance == nullptr){
        instance = new IdInstrRule;
        instance->setup();
    }
    return instance;
}
