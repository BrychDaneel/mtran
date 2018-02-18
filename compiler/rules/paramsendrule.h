#ifndef PARAMSENDRULE_H
#define PARAMSENDRULE_H

#include <baserule.h>

class ParamsEndRule : public BaseRule
{
    static ParamsEndRule* instance;
    ParamsEndRule();
public:
    static ParamsEndRule* getInstance();
};

#endif // PARAMSENDRULE_H
