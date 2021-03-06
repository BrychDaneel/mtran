#ifndef PARAMSENDRULE_H
#define PARAMSENDRULE_H

#include <baserule.h>

class ParamsEndRule : public BaseRule
{
    static ParamsEndRule* instance;
    void setup();
public:
    static ParamsEndRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // PARAMSENDRULE_H
