#ifndef PROGRAMRULE_H
#define PROGRAMRULE_H


#include <baserule.h>


class ProgramRule : public BaseRule
{
    static ProgramRule* instance;
    void setup();
public:
    static ProgramRule* getInstance();
};
#endif // PROGRAMRULE_H
