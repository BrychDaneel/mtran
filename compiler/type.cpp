#include "type.h"


Type::Type(BaseType type, std::vector<int> start, std::vector<int> end)
{
    this->start = start;
    this->dim = dim;
    this->type = type;

    int base_size;

    switch (type) {
    case BaseType::_boolean:
        base_size = 1;
        break;
    case BaseType::_char:
        base_size = 1;
        break;
    case BaseType::_string:
        base_size = 256;
        break;
    case BaseType::_integer:
        base_size = 4;
        break;
    case BaseType::_real:
        base_size = 4;
        break;
    }

    size = 1;
    for (int i=0; i<start.size(); i++)
        size *= end[i] - start[i];
}

Type::Type(BaseType type)
    :Type(type, std::vector<int>(), std::vector<int>())
{

}

std::vector<int> Type::getStart()
{
    return start;
}

std::vector<int> Type::getDim()
{
    return dim;
}

