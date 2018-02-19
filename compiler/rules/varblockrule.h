#ifndef VARBLOCKRULE_H
#define VARBLOCKRULE_H


#include <baserule.h>


class VarBlockRule : public BaseRule
{
    static VarBlockRule* instance;
    void setup();
public:
    static VarBlockRule* getInstance();
};

#endif // VARBLOCKRULE_H
