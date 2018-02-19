#ifndef PROCEDURERULE_H
#define PROCEDURERULE_H


#include <baserule.h>

class ProcedureRule : public BaseRule
{
    static ProcedureRule* instance;
    void setup();
public:
    static ProcedureRule* getInstance();
};

#endif // PROCEDURERULE_H
