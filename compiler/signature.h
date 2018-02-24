#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <type.h>
#include <vector>

class Signature
{
    Type result;
    std::vector<Type> params;
    int size = 0;
public:
    Signature(Type result, std::vector<Type> params);
    Signature(Type result);
    Signature();

    void addParam(Type type);
    void setResult(Type type);

    std::vector<Type> getParams();
    Type getResult();

    int getSize();

};

#endif // SIGNATURE_H
