#ifndef ROOTRULE_H
#define ROOTRULE_H


#include <baserule.h>
#include <nodes/rootnode.h>

class RootRule : public BaseRule
{
    static RootRule* instance;
    RootRule();
public:
    static RootRule* getInstance();
    virtual Node* getEmptyNode(int way) {return new RootNode();}
};

#endif // ROOTRULE_H
