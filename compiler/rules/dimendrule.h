#ifndef DIMENDRULE_H
#define DIMENDRULE_H

#include <baserule.h>

class DimEndRule : public BaseRule
{
    static DimEndRule* instance;
    void setup();
public:
    static DimEndRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};


#endif // DIMENDRULE_H
