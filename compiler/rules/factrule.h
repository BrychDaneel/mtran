#ifndef FACTRULE_H
#define FACTRULE_H

#include <baserule.h>

class FactRule : public BaseRule
{
    static FactRule* instance;
    void setup();
public:
    static FactRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // FACTRULE_H
