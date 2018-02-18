#ifndef CALLRULE_H
#define CALLRULE_H

#include <baserule.h>

class CallRule : public BaseRule
{
    static CallRule* instance;
    CallRule();
public:
    static CallRule* getInstance();
};

#endif // CALLRULE_H
