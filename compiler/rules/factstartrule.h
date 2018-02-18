#ifndef FACTSTARTRULE_H
#define FACTSTARTRULE_H

#include <baserule.h>

class FactStartRule : public BaseRule
{
    static FactStartRule* instance;
    void setup();
public:
    static FactStartRule* getInstance();
};

#endif // FACTSTARTRULE_H
