#ifndef IDLISTRULE_H
#define IDLISTRULE_H


#include <baserule.h>

class IdListRule : public BaseRule
{
    static IdListRule* instance;
    void setup();
public:
    static IdListRule* getInstance();
};

#endif // IDLISTRULE_H
