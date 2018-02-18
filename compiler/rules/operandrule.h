#ifndef OPERANDRULE_H
#define OPERANDRULE_H

#include <baserule.h>

class OperandRule : public BaseRule
{
    static OperandRule* instance;
    void setup();
public:
    static OperandRule* getInstance();
};

#endif // OPERANDRULE_H
