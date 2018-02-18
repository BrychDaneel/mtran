#include "literalrule.h"

#include <rules/terminalrule.h>
#include <tokens/integertoken.h>
#include <tokens/realtoken.h>
#include <tokens/chartoken.h>
#include <tokens/stringtoken.h>

LiteralRule* LiteralRule::instance;


LiteralRule::LiteralRule()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(IntegerToken::TYPE));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(RealToken::TYPE));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(CharToken::TYPE));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(StringToken::TYPE));
    vars.push_back(var);
}

LiteralRule *LiteralRule::getInstance()
{
    if (instance == nullptr){
        instance = new LiteralRule;
    }
    return instance;
}
