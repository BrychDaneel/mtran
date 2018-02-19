#ifndef ASSIGNRULE_H
#define ASSIGNRULE_H

#include <baserule.h>

class AssignRule : public BaseRule
{
    static AssignRule* instance;
    void setup();
public:
    static AssignRule* getInstance();
};

#endif // ASSIGNRULE_H
