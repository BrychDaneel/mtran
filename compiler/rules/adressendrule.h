#ifndef ADRESSENDRULE_H
#define ADRESSENDRULE_H

#include <baserule.h>

class AdressEndRule : public BaseRule
{
    static AdressEndRule* instance;
    void setup();
public:
    static AdressEndRule* getInstance();
};

#endif // ADRESSENDRULE_H
