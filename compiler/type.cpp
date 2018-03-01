#include "type.h"

#include <sstream>

Type::Type(BaseType type, std::vector<int> start, std::vector<int> dim)
{
    this->start = start;
    this->dim = dim;
    this->type = type;

    size = 1;

    switch (type) {
    case BaseType::_boolean:
        size = 1;
        break;
    case BaseType::_char:
        size = 1;
        break;
    case BaseType::_string:
        size = 32;
        break;
    case BaseType::_integer:
        size = 1;
        break;
    case BaseType::_real:
        size = 1;
        break;
    case BaseType::_void:
        size = 0;
    }

    for (unsigned int i=0; i<start.size(); i++)
        size *= dim[i];
}

Type::Type(BaseType type)
    :Type(type, std::vector<int>(), std::vector<int>())
{

}

BaseType Type::getBaseType()
{
    return type;
}

std::vector<int> Type::getStart()
{
    return start;
}

std::vector<int> Type::getDim()
{
    return dim;
}

int Type::getSize()
{
    return size;
}

bool Type::isSimple()
{
    return dim.size() == 0;
}

std::string Type::getStr()
{
    std::stringstream buf;
    switch (type) {
    case BaseType::_boolean:
        buf << "boolean";
        break;
    case BaseType::_char:
        buf << "char";
        break;
    case BaseType::_string:
        buf << "string";
        break;
    case BaseType::_integer:
        buf << "integer";
        break;
    case BaseType::_real:
        buf << "real";
        break;
    case BaseType::_void:
        buf << "void";
    }
    if (dim.size() > 0){
        buf << "[";
        for (size_t i=0; i<dim.size(); i++){
            buf << start[i];
            buf << "..";
            buf << start[i] + dim[i];
            if (i<dim.size()-1)
                buf << ", ";
        }
        buf << "]";
    }
    return buf.str();
}

