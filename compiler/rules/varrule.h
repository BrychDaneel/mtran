#ifndef VARRULE_H
#define VARRULE_H

#include <baserule.h>


class VarRule : public BaseRule
{
    static VarRule* instance;
    void setup();
public:
    static VarRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};

#endif // VARRULE_H
