#ifndef PROGRAMRULE_H
#define PROGRAMRULE_H


#include <baserule.h>


class ProgramRule : public BaseRule
{
    static ProgramRule* instance;
    void setup();
public:
    static ProgramRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};
#endif // PROGRAMRULE_H
