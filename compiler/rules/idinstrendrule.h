#ifndef IDINSTRENDRULE_H
#define IDINSTRENDRULE_H

#include <baserule.h>

class IdInstrEndRule : public BaseRule
{
    static IdInstrEndRule* instance;
    void setup();
public:
    static IdInstrEndRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // IDINSTRRULESTART_H
