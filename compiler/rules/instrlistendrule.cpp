#include "instrlistendrule.h"

#include <rules/terminalrule.h>
#include <tokens/semicolontoken.h>
#include <rules/instrlistrule.h>
#include <rules/emptyrule.h>

InstrListEndRule* InstrListEndRule::instance;


void InstrListEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(SemicolonToken::TYPE));
    var.push_back(InstrListRule::getInstance());
    vars.push_back(var);
}

InstrListEndRule *InstrListEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new InstrListEndRule;
        instance->setup();
    }
    return instance;
}
