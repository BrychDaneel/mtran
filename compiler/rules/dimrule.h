#ifndef DIMRULE_H
#define DIMRULE_H


#include <baserule.h>

class DimRule : public BaseRule
{
    static DimRule* instance;
    void setup();
public:
    static DimRule* getInstance();
};

#endif // DIMRULE_H
