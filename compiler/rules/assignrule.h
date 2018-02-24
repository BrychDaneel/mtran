#ifndef ASSIGNRULE_H
#define ASSIGNRULE_H

#include <baserule.h>

class AssignRule : public BaseRule
{
    static AssignRule* instance;
    void setup();
public:
    static AssignRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};

#endif // ASSIGNRULE_H
