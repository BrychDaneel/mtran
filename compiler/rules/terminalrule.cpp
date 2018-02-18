#include "terminalrule.h"
#include <iostream>
#include <nodes/terminalnode.h>


std::map<int, TerminalRule*> TerminalRule::instance;

TerminalRule::TerminalRule(int term)
{
    first.insert(term);
    this->term = term;
}

Rule *TerminalRule::getInstance(int term)
{
    if (instance.find(term) == instance.end()){
        instance[term] = new TerminalRule(term);
    }
    return instance[term];
}

Node *TerminalRule::parce(LexicalAnalizer *lex)
{
    if (lex->front()->getType() != term){
        std::cerr << "COMPILATION ERROR: Invalid terminal. Expected: " << term << std::endl;
        exit(1);
    }

    return new TerminalNode(lex->pop());
}
