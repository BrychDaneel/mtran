#include "idinstrendrule.h"

#include <rules/adressendrule.h>
#include <rules/callrule.h>
#include <rules/assignrule.h>

#include <nodes/idinstrnode.h>

IdInstrEndRule* IdInstrEndRule::instance;


void IdInstrEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(AdressEndRule::getInstance());
    var.push_back(AssignRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(CallRule::getInstance());
    vars.push_back(var);
}

IdInstrEndRule *IdInstrEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new IdInstrEndRule;
        instance->setup();
    }
    return instance;
}

Node *IdInstrEndRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new IdInstrNode(symbolTable, way, false);
}
