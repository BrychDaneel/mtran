#include "multioprule.h"

#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <tokens/facttoken.h>

MultiOpRule* MultiOpRule::instance;


MultiOpRule::MultiOpRule()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(FactToken::TYPE));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("div")));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("mod")));
    vars.push_back(var);
}

MultiOpRule *MultiOpRule::getInstance()
{
    if (instance == nullptr){
        instance = new MultiOpRule;
    }
    return instance;
}
