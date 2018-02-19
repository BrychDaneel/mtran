#include "rootrule.h"
#include <tokens/endtoken.h>

#include <rules/blockrule.h>
#include <rules/terminalrule.h>

RootRule* RootRule::instance;


void RootRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(BlockRule::getInstance());
    var.push_back(TerminalRule::getInstance(EndToken::TYPE));
    vars.push_back(var);
}

RootRule *RootRule::getInstance()
{
    if (instance == nullptr){
        instance = new RootRule;
        instance->setup();
    }
    return instance;
}
