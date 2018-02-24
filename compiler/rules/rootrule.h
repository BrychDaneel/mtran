#ifndef ROOTRULE_H
#define ROOTRULE_H


#include <baserule.h>
#include <nodes/rootnode.h>

class RootRule : public BaseRule
{
    static RootRule* instance;
    void setup();
public:
    static RootRule* getInstance();
    virtual Node* getEmptyNode(SymbolTable* symbolTable, int /*way*/) {return new RootNode(symbolTable);}
};

#endif // ROOTRULE_H
