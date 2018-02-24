#include "typerule.h"

#include <rules/terminalrule.h>
#include <tokens/idtoken.h>
#include <tokens/leftsquartoken.h>
#include <tokens/rightsquartoken.h>
#include <tokens/idtoken.h>
#include <keywordsfactory.h>
#include <rules/dimrule.h>

#include <nodes/typenode.h>

TypeRule* TypeRule::instance;


void TypeRule::setup()
{
    std::vector<Rule*> var;
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    vars.push_back(var);

    var.clear();
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("array")));
    var.push_back(TerminalRule::getInstance(LeftSquarToken::TYPE));
    var.push_back(DimRule::getInstance());
    var.push_back(TerminalRule::getInstance(RightSquarToken::TYPE));
    var.push_back(TerminalRule::getInstance(KeywordsFactory::getId("of")));
    var.push_back(TerminalRule::getInstance(IdToken::TYPE));
    vars.push_back(var);

}

TypeRule *TypeRule::getInstance()
{
    if (instance == nullptr){
        instance = new TypeRule;
        instance->setup();
    }
    return instance;
}

Node *TypeRule::getEmptyNode(SymbolTable *symbolTable, int way)
{
    return new TypeNode(symbolTable, way);
}
