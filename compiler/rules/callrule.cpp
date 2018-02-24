#include "callrule.h"

#include <rules/paramsrule.h>
#include <tokens/leftbrackettoken.h>
#include <tokens/rightbrackettoken.h>
#include <rules/terminalrule.h>

#include <nodes/callnode.h>

CallRule* CallRule::instance;


void CallRule::setup()
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
        instance->setup();
    }
    return instance;
}

Node *CallRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new CallNode(symbolTable, way);
}
