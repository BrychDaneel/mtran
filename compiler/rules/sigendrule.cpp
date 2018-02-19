#include "sigendrule.h"

#include <rules/emptyrule.h>
#include <rules/idlistrule.h>
#include <rules/terminalrule.h>
#include <tokens/semicolontoken.h>
#include <tokens/colontoken.h>
#include <rules/typerule.h>

SigEndRule* SigEndRule::instance;


void SigEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(SemicolonToken::TYPE));
    var.push_back(IdListRule::getInstance());
    var.push_back(TerminalRule::getInstance(ColonToken::TYPE));
    var.push_back(TypeRule::getInstance());
    var.push_back(SigEndRule::getInstance());
    vars.push_back(var);
}

SigEndRule *SigEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new SigEndRule;
        instance->setup();
    }
    return instance;
}
