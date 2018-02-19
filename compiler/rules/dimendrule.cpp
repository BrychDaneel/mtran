#include "dimendrule.h"

#include <rules/emptyrule.h>
#include <rules/terminalrule.h>
#include <tokens/comatoken.h>
#include <rules/rangerule.h>

DimEndRule* DimEndRule::instance;


void DimEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(ComaToken::TYPE));
    var.push_back(RangeRule::getInstance());
    var.push_back(DimEndRule::getInstance());
    vars.push_back(var);

}

DimEndRule *DimEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new DimEndRule;
        instance->setup();
    }
    return instance;
}
