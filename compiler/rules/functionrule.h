#ifndef FUNCTIONRULE_H
#define FUNCTIONRULE_H


#include <baserule.h>

class FunctionRule : public BaseRule
{
    static FunctionRule* instance;
    void setup();
public:
    static FunctionRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};


#endif // FUNCTIONRULE_H
