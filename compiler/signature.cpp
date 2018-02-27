#include "signature.h"

Signature::Signature(Type result, std::vector<Type> params)
{
    this->result = result;
    this->params = params;
    for (Type type : params)
        size += type.getSize();
    size += result.getSize();
}

Signature::Signature(Type result)
    : Signature(result, std::vector<Type>())
{

}

Signature::Signature()
    :Signature(Type(BaseType::_void))
{

}

void Signature::addParam(Type type)
{
    params.push_back(type);
    size += type.getSize();
}

void Signature::setResult(Type type)
{
    result = type;
    size += type.getSize();
}

std::vector<Type> Signature::getParams()
{
    return params;
}

Type Signature::getResult()
{
    return result;
}

int Signature::getSize()
{
    return size;
}
