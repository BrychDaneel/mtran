#ifndef INDEXRULE_H
#define INDEXRULE_H

#include <baserule.h>

class IndexRule : public BaseRule
{
    static IndexRule* instance;
    void setup();
public:
    static IndexRule* getInstance();
};

#endif // INDEXRULE_H
