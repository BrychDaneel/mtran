#ifndef EMPTYRULE_H
#define EMPTYRULE_H


#include <baserule.h>
#include <nodes/emptynode.h>


class EmptyRule : public BaseRule
{
    static EmptyRule* instance;
    EmptyRule();
    std::set<int> first;
    std::set<int> follow;
public:
    static EmptyRule* getInstance();
    Node* getEmptyNode(int way) {return new EmptyNode;}
    std::set<int> getFirst() {return first;}
    std::set<int> getFollow() {return follow;}
    Node* parce(LexicalAnalizer* lex);
    void build(int level = 0) {}
    bool addFollow(int term) {}
};

#endif // EMPTYRULE_H
