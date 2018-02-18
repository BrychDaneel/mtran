#ifndef PARAMSRULE_H
#define PARAMSRULE_H


#include <baserule.h>


class ParamsRule : public BaseRule
{
    static ParamsRule* instance;
    void setup();
public:
    static ParamsRule* getInstance();
};

#endif // PARAMSRULE_H
