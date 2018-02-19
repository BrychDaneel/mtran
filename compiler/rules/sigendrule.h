#ifndef SIGENDRULE_H
#define SIGENDRULE_H

#include <baserule.h>


class SigEndRule : public BaseRule
{
    static SigEndRule* instance;
    void setup();
public:
    static SigEndRule* getInstance();
};

#endif // SIGENDRULE_H
