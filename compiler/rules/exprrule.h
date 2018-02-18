#ifndef EXPRRULE_H
#define EXPRRULE_H

#include <baserule.h>


class ExprRule : public BaseRule
{
    static ExprRule* instance;
    ExprRule();
public:
    static ExprRule* getInstance();
};

#endif // EXPRRULE_H
