#ifndef EXPRENDRULE_H
#define EXPRENDRULE_H


#include <baserule.h>


class ExprEndRule : public BaseRule
{
    static ExprEndRule* instance;
    void setup();
public:
    static ExprEndRule* getInstance();
};

#endif // EXPRENDRULE_H
