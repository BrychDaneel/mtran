#include "sumendrule.h"

#include <rules/sumoprule.h>
#include <rules/sumrule.h>
#include <rules/emptyrule.h>

#include <nodes/binarnode.h>

SumEndRule* SumEndRule::instance;


void SumEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(SumOpRule::getInstance());
    var.push_back(SumRule::getInstance());
    vars.push_back(var);
}

SumEndRule *SumEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new SumEndRule;
        instance->setup();
    }
    return instance;
}

Node *SumEndRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new BinarNode(symbolTable, way, false);
}
