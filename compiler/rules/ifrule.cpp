#include "ifrule.h"

#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <rules/blockrule.h>
#include <rules/exprrule.h>
#include <rules/ifendrule.h>

IfRule* IfRule::instance;


void IfRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("if")));
    var.push_back(ExprRule::getInstance());
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("then")));
    var.push_back(BlockRule::getInstance());
    var.push_back(IfEndRule::getInstance());
    vars.push_back(var);
}

IfRule *IfRule::getInstance()
{
    if (instance == nullptr){
        instance = new IfRule;
        instance->setup();
    }
    return instance;
}
