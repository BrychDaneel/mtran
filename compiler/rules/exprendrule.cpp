#include "exprendrule.h"

#include <rules/sumrule.h>
#include <rules/terminalrule.h>
#include <tokens/eqtoken.h>
#include <rules/emptyrule.h>

#include <nodes/binarnode.h>
#include <rules/exprrule.h>

ExprEndRule* ExprEndRule::instance;


void ExprEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(EQToken::TYPE));
    var.push_back(ExprRule::getInstance());
    vars.push_back(var);
}

ExprEndRule *ExprEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new ExprEndRule;
        instance->setup();
    }
    return instance;
}

Node *ExprEndRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new BinarNode(symbolTable, way, false, true);
}
