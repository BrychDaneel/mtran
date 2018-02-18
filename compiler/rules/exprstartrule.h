#ifndef EXPRSTARTRULE_H
#define EXPRSTARTRULE_H


#include <baserule.h>

class ExprStartRule : public BaseRule
{
    static ExprStartRule* instance;
    void setup();
public:
    static ExprStartRule* getInstance();
};

#endif // EXPRSTARTRULE_H
