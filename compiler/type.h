#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <basetype.h>
#include <vector>

class Type
{
    BaseType type;
    std::vector<int> start;
    std::vector<int> dim;
    int size;

public:
    Type(){}
    Type(BaseType type, std::vector<int> start, std::vector<int> dim);
    Type(BaseType type);
    BaseType getBaseType();
    std::vector<int> getStart();
    std::vector<int> getDim();
    int getSize();
    bool isSimple();
    std::string getStr();
};

#endif // TYPE_H
