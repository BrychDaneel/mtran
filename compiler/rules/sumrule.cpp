#include "sumrule.h"

#include <rules/sumstartrule.h>
#include <rules/sumendrule.h>

#include <nodes/binarnode.h>

SumRule* SumRule::instance;


void SumRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(SumStartRule::getInstance());
    var.push_back(SumEndRule::getInstance());
    vars.push_back(var);
}

SumRule *SumRule::getInstance()
{
    if (instance == nullptr){
        instance = new SumRule;
        instance->setup();
    }
    return instance;
}

Node *SumRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new BinarNode(symbolTable, way, true);
}
