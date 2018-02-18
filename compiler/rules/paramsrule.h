#ifndef PARAMSRULE_H
#define PARAMSRULE_H


#include <baserule.h>


class ParamsRule : public BaseRule
{
    static ParamsRule* instance;
    ParamsRule();
public:
    static ParamsRule* getInstance();
};

#endif // PARAMSRULE_H
