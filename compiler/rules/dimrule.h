#ifndef DIMRULE_H
#define DIMRULE_H


#include <baserule.h>

class DimRule : public BaseRule
{
    static DimRule* instance;
    void setup();
public:
    static DimRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};

#endif // DIMRULE_H
