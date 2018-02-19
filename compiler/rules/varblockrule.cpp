#include "varblockrule.h"

#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <rules/varbodyrule.h>

VarBlockRule* VarBlockRule::instance;


void VarBlockRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("var")));
    var.push_back(VarBodyRule::getInstance());
    vars.push_back(var);

}

VarBlockRule *VarBlockRule::getInstance()
{
    if (instance == nullptr){
        instance = new VarBlockRule;
        instance->setup();
    }
    return instance;
}
