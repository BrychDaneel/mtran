#ifndef FORRULE_H
#define FORRULE_H


#include <baserule.h>

class ForRule : public BaseRule
{
    static ForRule* instance;
    void setup();
public:
    static ForRule* getInstance();
};

#endif // FORRULE_H
