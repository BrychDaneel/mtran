#ifndef DEFSRULE_H
#define DEFSRULE_H


#include <baserule.h>

class DefsRule : public BaseRule
{
    static DefsRule* instance;
    void setup();
public:
    static DefsRule* getInstance();
};

#endif // DEFSRULE_H
