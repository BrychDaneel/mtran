#include "defsrule.h"

#include <rules/emptyrule.h>
#include <rules/varblockrule.h>
#include <rules/functionrule.h>
#include <rules/procedurerule.h>

DefsRule* DefsRule::instance;


void DefsRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(VarBlockRule::getInstance());
    var.push_back(DefsRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(FunctionRule::getInstance());
    var.push_back(DefsRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(ProcedureRule::getInstance());
    var.push_back(DefsRule::getInstance());
    vars.push_back(var);

}

DefsRule *DefsRule::getInstance()
{
    if (instance == nullptr){
        instance = new DefsRule;
        instance->setup();
    }
    return instance;
}
