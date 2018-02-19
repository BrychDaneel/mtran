#include "forrule.h"


#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <rules/adressendrule.h>
#include <rules/exprrule.h>
#include <rules/blockrule.h>
#include <tokens/idtoken.h>
#include <rules/assignrule.h>

ForRule* ForRule::instance;


void ForRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("for")));
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    var.push_back(AdressEndRule::getInstance());
    var.push_back(AssignRule::getInstance());
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("to")));
    var.push_back(ExprRule::getInstance());
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("do")));
    var.push_back(BlockRule::getInstance());
    vars.push_back(var);
}

ForRule *ForRule::getInstance()
{
    if (instance == nullptr){
        instance = new ForRule;
        instance->setup();
    }
    return instance;
}
