#ifndef VARENDRULE_H
#define VARENDRULE_H

#include <baserule.h>


class VarEndRule : public BaseRule
{
    static VarEndRule* instance;
    VarEndRule();
public:
    static VarEndRule* getInstance();
};

#endif // VARENDRULE_H
