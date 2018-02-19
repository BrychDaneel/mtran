#include "prognamerule.h"

#include <tokens/idtoken.h>
#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <tokens/semicolontoken.h>
#include <rules/emptyrule.h>

ProgNameRule* ProgNameRule::instance;


void ProgNameRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("program")));
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    var.push_back(TerminalRule::getInstance(SemicolonToken::TYPE));
    vars.push_back(var);
}

ProgNameRule *ProgNameRule::getInstance()
{
    if (instance == nullptr){
        instance = new ProgNameRule;
        instance->setup();
    }
    return instance;
}
