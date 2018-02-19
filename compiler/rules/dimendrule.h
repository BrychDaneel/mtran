#ifndef DIMENDRULE_H
#define DIMENDRULE_H

#include <baserule.h>

class DimEndRule : public BaseRule
{
    static DimEndRule* instance;
    void setup();
public:
    static DimEndRule* getInstance();
};


#endif // DIMENDRULE_H
