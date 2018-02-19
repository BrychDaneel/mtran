#include "varbodyrule.h"

#include <rules/emptyrule.h>
#include <rules/idlistrule.h>
#include <rules/terminalrule.h>
#include <tokens/colontoken.h>
#include <tokens/semicolontoken.h>
#include <rules/typerule.h>

VarBodyRule* VarBodyRule::instance;


void VarBodyRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(EmptyRule::getInstance());
    vars.push_back(var);

    var.clear();
    var.push_back(IdListRule::getInstance());
    var.push_back(TerminalRule::getInstance(ColonToken::TYPE));
    var.push_back(TypeRule::getInstance());
    var.push_back(TerminalRule::getInstance(SemicolonToken::TYPE));

    var.push_back(VarBodyRule::getInstance());
    vars.push_back(var);

}

VarBodyRule *VarBodyRule::getInstance()
{
    if (instance == nullptr){
        instance = new VarBodyRule;
        instance->setup();
    }
    return instance;
}
