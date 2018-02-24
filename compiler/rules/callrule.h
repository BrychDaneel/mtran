#ifndef CALLRULE_H
#define CALLRULE_H

#include <baserule.h>

class CallRule : public BaseRule
{
    static CallRule* instance;
    void setup();
public:
    static CallRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};

#endif // CALLRULE_H
