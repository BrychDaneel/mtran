#ifndef LITERALRULE_H
#define LITERALRULE_H

#include <baserule.h>

class LiteralRule : public BaseRule
{
    static LiteralRule* instance;
    void setup();
public:
    static LiteralRule* getInstance();
    Node* getEmptyNode(SymbolTable *symbolTable, int way);
};

#endif // LITERALRULE_H
