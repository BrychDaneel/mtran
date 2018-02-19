#include "sigrule.h"
#include <rules/idlistrule.h>
#include <rules/terminalrule.h>
#include <tokens/colontoken.h>
#include <rules/typerule.h>
#include <rules/sigendrule.h>

SigRule* SigRule::instance;


void SigRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(IdListRule::getInstance());
    var.push_back(TerminalRule::getInstance(ColonToken::TYPE));
    var.push_back(TypeRule::getInstance());
    var.push_back(SigEndRule::getInstance());
    vars.push_back(var);
}

SigRule *SigRule::getInstance()
{
    if (instance == nullptr){
        instance = new SigRule;
        instance->setup();
    }
    return instance;
}
