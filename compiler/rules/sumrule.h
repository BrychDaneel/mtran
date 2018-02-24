#ifndef SUMRULE_H
#define SUMRULE_H

#include <baserule.h>

class SumRule : public BaseRule
{
    static SumRule* instance;
    void setup();
public:
    static SumRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // SUMRULE_H
