#ifndef SUMSTARTRULE_H
#define SUMSTARTRULE_H


#include <baserule.h>


class SumStartRule : public BaseRule
{
    static SumStartRule* instance;
    SumStartRule();
public:
    static SumStartRule* getInstance();
};

#endif // SUMSTARTRULE_H
