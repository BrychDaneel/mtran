#ifndef IDINSTRRULE_H
#define IDINSTRRULE_H



#include <baserule.h>


class IdInstrRule : public BaseRule
{
    static IdInstrRule* instance;
    void setup();
public:
    static IdInstrRule* getInstance();
};

#endif // IDINSTR_H
