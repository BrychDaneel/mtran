#ifndef INSTRRULE_H
#define INSTRRULE_H


#include <baserule.h>


class InstrRule : public BaseRule
{
    static InstrRule* instance;
    void setup();
public:
    static InstrRule* getInstance();
};

#endif // INSTRRULE_H
