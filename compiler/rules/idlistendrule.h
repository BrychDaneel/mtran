#ifndef IDLISTENDRULE_H
#define IDLISTENDRULE_H

#include <baserule.h>


class IdListEndRule : public BaseRule
{
    static IdListEndRule* instance;
    void setup();
public:
    static IdListEndRule* getInstance();
};

#endif // IDLISTENDRULE_H
