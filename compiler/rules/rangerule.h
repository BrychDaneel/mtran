#ifndef RANGERULE_H
#define RANGERULE_H

#include <baserule.h>


class RangeRule : public BaseRule
{
    static RangeRule* instance;
    void setup();
public:
    static RangeRule* getInstance();
};
#endif // RANGERULE_H
