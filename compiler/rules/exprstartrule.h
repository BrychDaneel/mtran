#ifndef EXPRSTARTRULE_H
#define EXPRSTARTRULE_H


#include <baserule.h>

class ExprStartRule : public BaseRule
{
    static ExprStartRule* instance;
    ExprStartRule();
public:
    static ExprStartRule* getInstance();
};

#endif // EXPRSTARTRULE_H
