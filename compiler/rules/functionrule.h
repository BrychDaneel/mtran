#ifndef FUNCTIONRULE_H
#define FUNCTIONRULE_H


#include <baserule.h>

class FunctionRule : public BaseRule
{
    static FunctionRule* instance;
    void setup();
public:
    static FunctionRule* getInstance();
};


#endif // FUNCTIONRULE_H
