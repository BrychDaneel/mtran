#ifndef BASERULE_H
#define BASERULE_H

#include <rule.h>
#include <vector>
#include <set>


class BaseRule : public Rule
{
protected:
    BaseRule();
    static Rule* instance;
    std::vector<std::vector<Rule*> > vars;
    std::set<int> first;
    std::set<int> follow;
    int emptyWay=-1;

    std::vector<std::set<int> > waysFirst;

    bool isFirstCached = false;
    bool isFollowCached = false;

    bool fistRecursion = false;

    int buildLevel = 0;

public:
    static Rule* getInstance();
    virtual Node* getEmptyNode(SymbolTable* symbolTable, int way);
    std::set<int> getFirst();
    std::set<int> getFollow();
    Node* parce(LexicalAnalizer* lex);
    void build(int level = 0);
    bool addFollow(int term);

};

#endif // BASERULE_H
