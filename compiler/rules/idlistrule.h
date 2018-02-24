#ifndef IDLISTRULE_H
#define IDLISTRULE_H


#include <baserule.h>

class IdListRule : public BaseRule
{
    static IdListRule* instance;
    void setup();
public:
    static IdListRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};

#endif // IDLISTRULE_H
