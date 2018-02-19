#include "ifendrule.h"

#include <keywordsfactory.h>
#include <rules/terminalrule.h>
#include <rules/blockrule.h>
#include <rules/emptyrule.h>

IfEndRule* IfEndRule::instance;


void IfEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("else")));
    var.push_back(BlockRule::getInstance());
    vars.push_back(var);
}

IfEndRule *IfEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new IfEndRule;
        instance->setup();
    }
    return instance;
}
