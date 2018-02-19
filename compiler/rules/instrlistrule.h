#ifndef INSTRLISTRULE_H
#define INSTRLISTRULE_H


#include <baserule.h>

class InstrListRule : public BaseRule
{
    static InstrListRule* instance;
    void setup();
public:
    static InstrListRule* getInstance();
};

#endif // INSTRLISTRULE_H
