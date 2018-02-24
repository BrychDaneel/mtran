#include "assignrule.h"


#include <rules/terminalrule.h>
#include <rules/exprrule.h>
#include <tokens/assigntoken.h>

#include <nodes/assignnode.h>

AssignRule* AssignRule::instance;


void AssignRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(AssignToken::TYPE));
    var.push_back(ExprRule::getInstance());
    vars.push_back(var);
}

AssignRule *AssignRule::getInstance()
{
    if (instance == nullptr){
        instance = new AssignRule;
        instance->setup();
    }
    return instance;
}

Node *AssignRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new AssignNode(symbolTable, way);
}
