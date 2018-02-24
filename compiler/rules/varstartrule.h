#ifndef VARSTARTRULE_H
#define VARSTARTRULE_H

#include <baserule.h>

class VarStartRule : public BaseRule
{
    static VarStartRule* instance;
    void setup();
public:
    static VarStartRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};

#endif // VARSTARTRULE_H
