#ifndef YNOOPRULE_H
#define YNOOPRULE_H


#include <baserule.h>

class YnoOpRule : public BaseRule
{
    static YnoOpRule* instance;
    YnoOpRule();
public:
    static YnoOpRule* getInstance();
};

#endif // YNOOPRULE_H
