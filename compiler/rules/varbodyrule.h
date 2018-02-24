#ifndef VARBODYRULE_H
#define VARBODYRULE_H


#include <baserule.h>


class VarBodyRule : public BaseRule
{
    static VarBodyRule* instance;
    void setup();
public:
    static VarBodyRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};


#endif // VARBODYRULE_H
