#ifndef PROCEDURERULE_H
#define PROCEDURERULE_H


#include <baserule.h>

class ProcedureRule : public BaseRule
{
    static ProcedureRule* instance;
    void setup();
public:
    static ProcedureRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way) override;
};

#endif // PROCEDURERULE_H
