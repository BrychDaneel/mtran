#include "procedurerule.h"

#include <rules/terminalrule.h>
#include <keywordsfactory.h>
#include <rules/sigrule.h>
#include <rules/defsrule.h>
#include <rules/instrlistrule.h>
#include <tokens/leftbrackettoken.h>
#include <tokens/rightbrackettoken.h>
#include <tokens/colontoken.h>
#include <tokens/semicolontoken.h>
#include <tokens/idtoken.h>

ProcedureRule* ProcedureRule::instance;


void ProcedureRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("procedure")));
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    var.push_back(TerminalRule::getInstance(LeftBracketToken::TYPE));
    var.push_back(SigRule::getInstance());
    var.push_back(TerminalRule::getInstance(RightBracketToken::TYPE));

    var.push_back(TerminalRule::getInstance(SemicolonToken::TYPE));

    var.push_back(DefsRule::getInstance());

    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("begin")));
    var.push_back(InstrListRule::getInstance());
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("end")));

    vars.push_back(var);
}

ProcedureRule *ProcedureRule::getInstance()
{
    if (instance == nullptr){
        instance = new ProcedureRule;
        instance->setup();
    }
    return instance;
}
