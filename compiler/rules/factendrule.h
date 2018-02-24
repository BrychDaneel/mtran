#ifndef FACTENDRULE_H
#define FACTENDRULE_H

#include <baserule.h>

class FactEndRule : public BaseRule
{
    static FactEndRule* instance;
    void setup();
public:
    static FactEndRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // FACTENDRULE_H
