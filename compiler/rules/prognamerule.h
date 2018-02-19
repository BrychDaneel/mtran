#ifndef PROGNAMERULE_H
#define PROGNAMERULE_H


#include <baserule.h>


class ProgNameRule : public BaseRule
{
    static ProgNameRule* instance;
    void setup();
public:
    static ProgNameRule* getInstance();
};

#endif // PROGNAMERULE_H
