#ifndef IFRULE_H
#define IFRULE_H


#include <baserule.h>

class IfRule : public BaseRule
{
    static IfRule* instance;
    void setup();
public:
    static IfRule* getInstance();
};

#endif // IFRULE_H
