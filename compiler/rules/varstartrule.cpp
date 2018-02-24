#include "varstartrule.h"

#include <rules/terminalrule.h>
#include <tokens/idtoken.h>

#include <nodes/idnode.h>

VarStartRule* VarStartRule::instance;


void VarStartRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    vars.push_back(var);
}

VarStartRule *VarStartRule::getInstance()
{
    if (instance == nullptr){
        instance = new VarStartRule;
        instance->setup();
    }
    return instance;
}

Node *VarStartRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new IdNode(symbolTable, way);
}
