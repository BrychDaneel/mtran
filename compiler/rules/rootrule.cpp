#include "rootrule.h"
#include <tokens/endtoken.h>

#include <rules/exprrule.h>
#include <rules/terminalrule.h>

RootRule* RootRule::instance;


RootRule::RootRule()
{
    std::vector<Rule*> var;
    var.push_back(ExprRule::getInstance());
    var.push_back(TerminalRule::getInstance(EndToken::TYPE));
    vars.push_back(var);
}

RootRule *RootRule::getInstance()
{
    if (instance == nullptr){
        instance = new RootRule;
    }
    return instance;
}
