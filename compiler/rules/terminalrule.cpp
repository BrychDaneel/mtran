#include "terminalrule.h"
#include <iostream>
#include <nodes/terminalnode.h>
#include <sstream>
#include <errorlog.h>
#include <nodes/emptynode.h>

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
    std::stringstream buf;
    if (lex->front()->getType() != term){
        buf << "COMPILATION ERROR(" << lex->getLine() << "," << lex->getPosition() << "): Missed token: ";
        buf << ErrorLog::getTokenStr(term);
        ErrorLog::SyntaxError(buf.str());
        return new EmptyNode;
    }

    return new TerminalNode(lex->getSymbolTable(), lex->pop());
}
