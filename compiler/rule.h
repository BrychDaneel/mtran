#ifndef RULE_H
#define RULE_H


#include <set>
#include <lexicalanalizer.h>
#include <node.h>

class Rule
{
public:
    virtual void build(int level=0) = 0;
    virtual std::set<int> getFirst() = 0;
    virtual std::set<int> getFollow() = 0;
    virtual bool addFollow(int term) = 0;
    virtual Node* parce(LexicalAnalizer* lex) = 0;
    virtual ~Rule (){}
};

#endif // RULE_H
