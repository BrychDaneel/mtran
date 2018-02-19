#include "programrule.h"

#include <rules/prognamerule.h>
#include <rules/defsrule.h>
#include <rules/blockrule.h>
#include <rules/terminalrule.h>
#include <tokens/dottoken.h>

ProgramRule* ProgramRule::instance;


void ProgramRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(ProgNameRule::getInstance());
    var.push_back(DefsRule::getInstance());
    var.push_back(BlockRule::getInstance());
    var.push_back(TerminalRule::getInstance(DotToken::TYPE));
    vars.push_back(var);
}

ProgramRule *ProgramRule::getInstance()
{
    if (instance == nullptr){
        instance = new ProgramRule;
        instance->setup();
    }
    return instance;
}
