#include "dimrule.h"

#include <rules/rangerule.h>
#include <rules/dimendrule.h>

DimRule* DimRule::instance;


void DimRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(RangeRule::getInstance());
    var.push_back(DimEndRule::getInstance());
    vars.push_back(var);

}

DimRule *DimRule::getInstance()
{
    if (instance == nullptr){
        instance = new DimRule;
        instance->setup();
    }
    return instance;
}
