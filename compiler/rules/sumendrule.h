#ifndef SUMENDRULE_H
#define SUMENDRULE_H


#include <baserule.h>


class SumEndRule : public BaseRule
{
    static SumEndRule* instance;
    void setup();
public:
    static SumEndRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // SUMENDRULE_H
