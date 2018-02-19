#include "functionrule.h"

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

FunctionRule* FunctionRule::instance;


void FunctionRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("function")));
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    var.push_back(TerminalRule::getInstance(LeftBracketToken::TYPE));
    var.push_back(SigRule::getInstance());
    var.push_back(TerminalRule::getInstance(RightBracketToken::TYPE));

    var.push_back(TerminalRule::getInstance(ColonToken::TYPE));
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    var.push_back(TerminalRule::getInstance(SemicolonToken::TYPE));

    var.push_back(DefsRule::getInstance());

    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("begin")));
    var.push_back(InstrListRule::getInstance());
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("end")));

    vars.push_back(var);
}

FunctionRule *FunctionRule::getInstance()
{
    if (instance == nullptr){
        instance = new FunctionRule;
        instance->setup();
    }
    return instance;
}
