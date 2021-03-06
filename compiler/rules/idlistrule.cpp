#include "idlistrule.h"

#include <rules/terminalrule.h>
#include <tokens/idtoken.h>
#include <rules/idlistendrule.h>
#include <nodes/idlistnode.h>

IdListRule* IdListRule::instance;


void IdListRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    var.push_back(IdListEndRule::getInstance());
    vars.push_back(var);
}

IdListRule *IdListRule::getInstance()
{
    if (instance == nullptr){
        instance = new IdListRule;
        instance->setup();
    }
    return instance;
}

Node *IdListRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new IdListNode(symbolTable, way, true);
}
