#ifndef FACTENDRULE_H
#define FACTENDRULE_H

#include <baserule.h>

class FactEndRule : public BaseRule
{
    static FactEndRule* instance;
    void setup();
public:
    static FactEndRule* getInstance();
};

#endif // FACTENDRULE_H
