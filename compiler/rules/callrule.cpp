#include "callrule.h"

#include <rules/paramsrule.h>
#include <tokens/leftbrackettoken.h>
#include <tokens/rightbrackettoken.h>
#include <rules/terminalrule.h>


CallRule* CallRule::instance;


CallRule::CallRule()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(LeftBracketToken::TYPE));
    var.push_back(ParamsRule::getInstance());
    var.push_back(TerminalRule::getInstance(RightBracketToken::TYPE));
    vars.push_back(var);
}

CallRule *CallRule::getInstance()
{
    if (instance == nullptr){
        instance = new CallRule;
    }
    return instance;
}
