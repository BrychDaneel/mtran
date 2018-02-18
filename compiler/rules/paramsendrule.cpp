#include "paramsendrule.h"

#include <rules/emptyrule.h>
#include <tokens/comatoken.h>
#include <rules/exprrule.h>
#include <rules/terminalrule.h>
#include <rules/paramsrule.h>

ParamsEndRule* ParamsEndRule::instance;


ParamsEndRule::ParamsEndRule()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(ComaToken::TYPE));
    var.push_back(ParamsRule::getInstance());
    vars.push_back(var);

}

ParamsEndRule *ParamsEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new ParamsEndRule;
    }
    return instance;
}
