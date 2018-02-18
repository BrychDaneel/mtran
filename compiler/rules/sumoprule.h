#ifndef SUMOPRULE_H
#define SUMOPRULE_H

#include <baserule.h>

class SumOpRule : public BaseRule
{
    static SumOpRule* instance;
    void setup();
public:
    static SumOpRule* getInstance();
};

#endif // SUMOPRULE_H
