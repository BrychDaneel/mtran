#ifndef CONTROLRULE_H
#define CONTROLRULE_H

#include <baserule.h>

class ControlRule : public BaseRule
{
    static ControlRule* instance;
    void setup();
public:
    static ControlRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};

#endif // CONTROLRULE_H
