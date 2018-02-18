#ifndef LITERALRULE_H
#define LITERALRULE_H

#include <baserule.h>

class LiteralRule : public BaseRule
{
    static LiteralRule* instance;
    void setup();
public:
    static LiteralRule* getInstance();
};

#endif // LITERALRULE_H
