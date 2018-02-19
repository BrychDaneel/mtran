#include "whilerule.h"

#include <keywordsfactory.h>
#include <rules/terminalrule.h>
#include <rules/blockrule.h>
#include <rules/exprrule.h>

WhileRule* WhileRule::instance;


void WhileRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("while")));
    var.push_back(ExprRule::getInstance());
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("do")));
    var.push_back(BlockRule::getInstance());
    vars.push_back(var);
}

WhileRule *WhileRule::getInstance()
{
    if (instance == nullptr){
        instance = new WhileRule;
        instance->setup();
    }
    return instance;
}
