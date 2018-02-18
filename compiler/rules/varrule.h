#ifndef VARRULE_H
#define VARRULE_H

#include <baserule.h>


class VarRule : public BaseRule
{
    static VarRule* instance;
    void setup();
public:
    static VarRule* getInstance();
};

#endif // VARRULE_H
