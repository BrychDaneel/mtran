#ifndef WHILERULE_H
#define WHILERULE_H


#include <baserule.h>


class WhileRule : public BaseRule
{
    static WhileRule* instance;
    void setup();
public:
    static WhileRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // WHILERULE_H
