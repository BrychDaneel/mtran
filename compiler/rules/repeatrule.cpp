#include "repeatrule.h"

#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <rules/exprrule.h>
#include <rules/instrlistrule.h>

#include <nodes/repeatnode.h>

RepeatRule* RepeatRule::instance;


void RepeatRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("repeat")));
    var.push_back(InstrListRule::getInstance());
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("until")));
    var.push_back(ExprRule::getInstance());
    vars.push_back(var);
}

RepeatRule *RepeatRule::getInstance()
{
    if (instance == nullptr){
        instance = new RepeatRule;
        instance->setup();
    }
    return instance;
}

Node *RepeatRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new RepeatNode(symbolTable, way);
}
