#ifndef TERMINALRULE_H
#define TERMINALRULE_H

#include <rule.h>
#include <token.h>
#include <map>

class TerminalRule : public Rule
{
protected:
    TerminalRule(int term);
    std::set<int> follow;
    std::set<int> first;
    int term;
    static std::map<int, TerminalRule*> instance;

public:
    static Rule* getInstance(int term);
    void build(int /*level=0*/) {}
    std::set<int> getFirst() {return first;}
    std::set<int> getFollow() {return follow;}
    bool addFollow(int /*term*/) {return false;}
    Node* parce(LexicalAnalizer* lex);
};

#endif // TERMINALRULE_H
