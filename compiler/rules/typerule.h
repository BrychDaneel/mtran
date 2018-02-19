#ifndef TYPERULE_H
#define TYPERULE_H


#include <baserule.h>


class TypeRule : public BaseRule
{
    static TypeRule* instance;
    void setup();
public:
    static TypeRule* getInstance();
};


#endif // TYPERULE_H
