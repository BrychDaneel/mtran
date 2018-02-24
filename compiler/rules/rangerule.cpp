#include "rangerule.h"

#include <rules/terminalrule.h>
#include <tokens/dotdottoken.h>
#include <tokens/integertoken.h>

#include <nodes/rangenode.h>

RangeRule* RangeRule::instance;


void RangeRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(IntegerToken::TYPE));
    var.push_back(TerminalRule::getInstance(DotDotToken::TYPE));
    var.push_back(TerminalRule::getInstance(IntegerToken::TYPE));
    vars.push_back(var);
}

RangeRule *RangeRule::getInstance()
{
    if (instance == nullptr){
        instance = new RangeRule;
        instance->setup();
    }
    return instance;
}

Node *RangeRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new RangeNode(symbolTable, way);
}
