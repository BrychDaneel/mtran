#include "blockrule.h"

#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <rules/instrrule.h>
#include <rules/instrlistrule.h>

BlockRule* BlockRule::instance;


void BlockRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(InstrRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("begin")));
    var.push_back(InstrListRule::getInstance());
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("end")));
    vars.push_back(var);
}

BlockRule *BlockRule::getInstance()
{
    if (instance == nullptr){
        instance = new BlockRule;
        instance->setup();
    }
    return instance;
}
