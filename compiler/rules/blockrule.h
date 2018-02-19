#ifndef BLOCKRULE_H
#define BLOCKRULE_H

#include <baserule.h>

class BlockRule : public BaseRule
{
    static BlockRule* instance;
    void setup();
public:
    static BlockRule* getInstance();
};

#endif // BLOCKRULE_H
