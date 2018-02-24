#ifndef SIGENDRULE_H
#define SIGENDRULE_H

#include <baserule.h>


class SigEndRule : public BaseRule
{
    static SigEndRule* instance;
    void setup();
public:
    static SigEndRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // SIGENDRULE_H
