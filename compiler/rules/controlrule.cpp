#include "controlrule.h"

#include <rules/terminalrule.h>
#include <rules/exprrule.h>
#include <keywordsfactory.h>
#include <tokens/leftbrackettoken.h>
#include <tokens/rightbrackettoken.h>

#include <nodes/controlnode.h>

ControlRule* ControlRule::instance;


void ControlRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("break")));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("continue")));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("exit")));
    var.push_back(TerminalRule::getInstance(LeftBracketToken::TYPE));
    var.push_back(ExprRule::getInstance());
    var.push_back(TerminalRule::getInstance(RightBracketToken::TYPE));
    vars.push_back(var);
}

ControlRule *ControlRule::getInstance()
{
    if (instance == nullptr){
        instance = new ControlRule;
        instance->setup();
    }
    return instance;
}

Node *ControlRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new ControlNode(symbolTable, way);
}
