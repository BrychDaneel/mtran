#include "varrule.h"

#include <rules/literalrule.h>
#include <rules/exprrule.h>
#include <rules/varstartrule.h>
#include <rules/varendrule.h>
#include <rules/terminalrule.h>

#include <tokens/leftbrackettoken.h>
#include <tokens/rightbrackettoken.h>

VarRule* VarRule::instance;


VarRule::VarRule()
{
    std::vector<Rule*> var;
    var.push_back(VarStartRule::getInstance());
    var.push_back(VarEndRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(LiteralRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(LeftBracketToken::TYPE));
    var.push_back(ExprRule::getInstance());
    var.push_back(TerminalRule::getInstance(RightBracketToken::TYPE));
    vars.push_back(var);
}

VarRule *VarRule::getInstance()
{
    if (instance == nullptr){
        instance = new VarRule;
    }
    return instance;
}
