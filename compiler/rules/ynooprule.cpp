#include "ynooprule.h"

#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <tokens/sumtoken.h>

YnoOpRule* YnoOpRule::instance;


YnoOpRule::YnoOpRule()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(SumToken::TYPE));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("not")));
    vars.push_back(var);
}

YnoOpRule *YnoOpRule::getInstance()
{
    if (instance == nullptr){
        instance = new YnoOpRule;
    }
    return instance;
}
