#ifndef PARAMSRULE_H
#define PARAMSRULE_H


#include <baserule.h>


class ParamsRule : public BaseRule
{
    static ParamsRule* instance;
    void setup();
public:
    static ParamsRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // PARAMSRULE_H
