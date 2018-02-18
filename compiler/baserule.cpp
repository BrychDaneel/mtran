#include "baserule.h"
#include <basenode.h>
#include <iostream>
#include <tokens/emptytoken.h>
#include <token.h>

Rule* BaseRule::instance = nullptr;


BaseRule::BaseRule()
{

}

Rule *BaseRule::getInstance()
{
    if (instance == nullptr){
        instance = new BaseRule;
    }
    return instance;
}

std::set<int> BaseRule::getFirst()
{
    if (isFirstCached)
        return first;

    if (fistRecursion){
        std::cerr << "GRAMATIC ERROR: Left recursion found(while first() )" << std::endl;
        exit(1);
    }

    fistRecursion = true;

    while (waysFirst.size() < vars.size())
        waysFirst.push_back(std::set<int>());

    for (size_t way=0; way<vars.size(); way++){
        size_t i=0;
        bool hasEmpty = true;
        while (hasEmpty && i<vars[way].size()){
            hasEmpty = false;
            for (int f : vars[way][i]->getFirst())
                if (f == EmptyToken::TYPE)
                    hasEmpty = true;
                else
                    waysFirst[way].insert(f);
         }

        if  (i == vars[way].size() && hasEmpty){
            waysFirst[way].insert(EmptyToken::TYPE);
            emptyWay = way;
        }
    }

    for (std::set<int>& wfrsts : waysFirst)
        for (int f : wfrsts)
            if (first.find(f) != first.end()){
                std::cerr << "GRAMATIC ERROR: Ways collision" << std::endl;
                exit(1);
            }
            else
                first.insert(f);

    isFirstCached = true;
    return first;
}

std::set<int> BaseRule::getFollow()
{
    if (!isFollowCached){
        std::cerr << "RUNTIME ERROR: Gramatic is not builded" << std::endl;
        exit(1);
    }

    return follow;
}

Node *BaseRule::parce(LexicalAnalizer *lex)
{
    if (!isFollowCached){
        std::cerr << "RUNTIME ERROR: Gramatic is not builded" << std::endl;
        exit(1);
    }

    Token* token = lex->front();
    int term = token->getType();

    int way = -1;
    if (emptyWay > -1 && follow.find(term) != follow.end())
        way = emptyWay;

    if (way == -1)
        for (size_t i=0; i<vars.size(); i++)
            if (waysFirst[i].find(term) != waysFirst[i].end()){
                way = i;
                break;
            }

    if (way == -1){
        std::cerr << "COMPILATION ERROR: Invalid token" << std::endl;
        exit(1);
    }

    Node* node = getEmptyNode(way);

    for (Rule* rule : vars[way])
        node->add(rule->parce(lex));

    return node;
}

Node *BaseRule::getEmptyNode(int way)
{
    return new BaseNode(way);
}

void BaseRule::build(int level)
{
    isFollowCached = true;

    if (level==1 || !level){
        if (level==buildLevel && level)
            return;
        getFirst();
        buildLevel = 1;
        for (std::vector<Rule*>& way : vars)
            for (Rule* rule: way)
                rule->build(1);
    }

    if (level==2 || !level){
        if (level==buildLevel)
            return;
        buildLevel = 2;
        for (size_t way=0; way<vars.size(); way++){
            for (size_t i=0; i<vars[way].size(); i++)
                for (size_t j=i+1; j<vars[way].size(); j++){
                    for (int term: vars[way][j]->getFirst())
                        if (term!=EmptyToken::TYPE)
                            vars[way][i]->addFollow(term);

                    if (vars[way][j]->getFirst().find(EmptyToken::TYPE) == vars[way][j]->getFirst().end())
                        break;
                }
        }

        for (std::vector<Rule*>& way : vars)
            for (Rule* rule: way)
                rule->build(2);
    }

    if (level==3 || !level){
        std::set<Rule*> modyfy;
        for (size_t way=0; way<vars.size(); way++){
            for (int i=vars[way].size()-1; i>=0; i--){

                for (int term : follow)
                    if (vars[way][i]->addFollow(term))
                        modyfy.insert(vars[way][i]);

                if (vars[way][i]->getFirst().find(EmptyToken::TYPE) == vars[way][i]->getFirst().end())
                    break;
            }
        }

        for (Rule* rule : modyfy)
            rule->build(3);
    }
}

bool BaseRule::addFollow(int term)
{
    if (emptyWay>-1 && first.find(term) != first.end()){
        std::cerr << "GRAMATIC ERROR: First Follow collision" << std::endl;
        exit(1);
    }

    if (follow.find(term) != follow.end())
        return false;

    follow.insert(term);
    return true;
}



