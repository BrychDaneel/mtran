#ifndef SUMSTARTRULE_H
#define SUMSTARTRULE_H


#include <baserule.h>


class SumStartRule : public BaseRule
{
    static SumStartRule* instance;
    void setup();
public:
    static SumStartRule* getInstance();
    Node* getEmptyNode(SymbolTable *symbolTable, int way);
};

#endif // SUMSTARTRULE_H
