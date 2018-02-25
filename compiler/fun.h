#ifndef FUN_H
#define FUN_H

#include <vector>
#include <idinfo.h>
#include <type.h>

class Fun
{
public:
    virtual bool canAccept(std::vector<Type> types) = 0;
    void call(std::vector<Type> paramsType, std::vector<int>);
};

#endif // FUN_H
