#ifndef REPEATRULE_H
#define REPEATRULE_H


#include <baserule.h>


class RepeatRule : public BaseRule
{
    static RepeatRule* instance;
    void setup();
public:
    static RepeatRule* getInstance();
};

#endif // REPEATRULE_H
