#include "idlistendrule.h"

#include <rules/emptyrule.h>
#include <rules/terminalrule.h>
#include <tokens/idtoken.h>
#include <tokens/comatoken.h>
#include <nodes/idlistnode.h>

IdListEndRule* IdListEndRule::instance;


void IdListEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(ComaToken::TYPE));
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    var.push_back(IdListEndRule::getInstance());
    vars.push_back(var);
}

IdListEndRule *IdListEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new IdListEndRule;
        instance->setup();
    }
    return instance;
}

Node *IdListEndRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new IdListNode(symbolTable, way, false);
}
