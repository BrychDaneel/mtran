#ifndef SIGRULE_H
#define SIGRULE_H


#include <baserule.h>


class SigRule : public BaseRule
{
    static SigRule* instance;
    void setup();
public:
    static SigRule* getInstance();
};


#endif // SIGRULE_H
