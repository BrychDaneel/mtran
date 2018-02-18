#include "indexrule.h"

#include <rules/terminalrule.h>
#include <tokens/leftsquartoken.h>
#include <tokens/rightsquartoken.h>
#include <rules/paramsrule.h>

IndexRule* IndexRule::instance;


IndexRule::IndexRule()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(LeftSquarToken::TYPE));
    var.push_back(ParamsRule::getInstance());
    var.push_back(TerminalRule::getInstance(RightSquarToken::TYPE));
    vars.push_back(var);
}

IndexRule *IndexRule::getInstance()
{
    if (instance == nullptr){
        instance = new IndexRule;
    }
    return instance;
}
