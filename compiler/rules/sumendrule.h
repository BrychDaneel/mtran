#ifndef SUMENDRULE_H
#define SUMENDRULE_H


#include <baserule.h>


class SumEndRule : public BaseRule
{
    static SumEndRule* instance;
    SumEndRule();
public:
    static SumEndRule* getInstance();
};

#endif // SUMENDRULE_H
