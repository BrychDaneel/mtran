#ifndef IDLISTENDRULE_H
#define IDLISTENDRULE_H

#include <baserule.h>


class IdListEndRule : public BaseRule
{
    static IdListEndRule* instance;
    void setup();
public:
    static IdListEndRule* getInstance();
    Node* getEmptyNode(SymbolTable* symbolTable, int way);
};

#endif // IDLISTENDRULE_H
