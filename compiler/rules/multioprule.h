#ifndef MULTIOPRULE_H
#define MULTIOPRULE_H

#include <baserule.h>

class MultiOpRule : public BaseRule
{
    static MultiOpRule* instance;
    MultiOpRule();
public:
    static MultiOpRule* getInstance();
};

#endif // MULTIOPRULE_H
