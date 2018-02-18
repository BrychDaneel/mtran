#include "varendrule.h"

#include <rules/emptyrule.h>
#include <rules/indexrule.h>
#include <rules/callrule.h>

VarEndRule* VarEndRule::instance;


void VarEndRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(CallRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(IndexRule::getInstance());
    vars.push_back(var);

}

VarEndRule *VarEndRule::getInstance()
{
    if (instance == nullptr){
        instance = new VarEndRule;
        instance->setup();
    }
    return instance;
}
