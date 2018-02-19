#ifndef IFENDRULE_H
#define IFENDRULE_H


#include <baserule.h>

class IfEndRule : public BaseRule
{
    static IfEndRule* instance;
    void setup();
public:
    static IfEndRule* getInstance();
};

#endif // IFENDRULE_H
