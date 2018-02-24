#ifndef FACTSTARTRULE_H
#define FACTSTARTRULE_H

#include <baserule.h>

class FactStartRule : public BaseRule
{
    static FactStartRule* instance;
    void setup();
public:
    static FactStartRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // FACTSTARTRULE_H
