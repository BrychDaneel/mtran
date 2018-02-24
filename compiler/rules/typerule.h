#ifndef TYPERULE_H
#define TYPERULE_H


#include <baserule.h>


class TypeRule : public BaseRule
{
    static TypeRule* instance;
    void setup();
public:
    static TypeRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};


#endif // TYPERULE_H
