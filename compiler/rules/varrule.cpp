#include "varrule.h"

#include <rules/literalrule.h>
#include <rules/exprrule.h>
#include <rules/varstartrule.h>
#include <rules/varendrule.h>
#include <rules/terminalrule.h>

#include <tokens/leftbrackettoken.h>
#include <tokens/rightbrackettoken.h>

#include <nodes/varnode.h>

VarRule* VarRule::instance;


void VarRule::setup()
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
        instance->setup();
    }
    return instance;
}

Node *VarRule::getEmptyNode(SymbolTable* symbolTable, int way)
{
    return new VarNode(symbolTable, way);
}
