#ifndef SUMRULE_H
#define SUMRULE_H

#include <baserule.h>

class SumRule : public BaseRule
{
    static SumRule* instance;
    void setup();
public:
    static SumRule* getInstance();
};

#endif // SUMRULE_H
