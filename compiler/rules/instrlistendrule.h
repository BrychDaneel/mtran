#ifndef INSTRLISTENDRULE_H
#define INSTRLISTENDRULE_H

#include <baserule.h>

class InstrListEndRule : public BaseRule
{
    static InstrListEndRule* instance;
    void setup();
public:
    static InstrListEndRule* getInstance();
};

#endif // INSTRLISTENDRULE_H
