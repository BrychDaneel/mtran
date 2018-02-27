#ifndef INDEXRULE_H
#define INDEXRULE_H

#include <baserule.h>

class IndexRule : public BaseRule
{
    static IndexRule* instance;
    void setup();
public:
    static IndexRule* getInstance();
    Node* getEmptyNode(SymbolTable *symbolTable, int way) override;
};

#endif // INDEXRULE_H
