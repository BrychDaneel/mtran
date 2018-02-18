#include "sumoprule.h"

#include <tokens/sumtoken.h>
#include <keywordsfactory.h>
#include <rules/terminalrule.h>

SumOpRule* SumOpRule::instance;


SumOpRule::SumOpRule()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(SumToken::TYPE));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("and")));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("or")));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("xor")));
    vars.push_back(var);
}

SumOpRule *SumOpRule::getInstance()
{
    if (instance == nullptr){
        instance = new SumOpRule;
    }
    return instance;
}
