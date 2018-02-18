#ifndef PARAMSSTARTRULE_H
#define PARAMSSTARTRULE_H


#include <baserule.h>

class ParamsStartRule : public BaseRule
{
    static ParamsStartRule* instance;
    ParamsStartRule();
public:
    static ParamsStartRule* getInstance();
};

#endif // PARAMSSTARTRULE_H
