#ifndef TYPECONVERTOR_H
#define TYPECONVERTOR_H

#include <type.h>
#include <nodes/virtualexprnode.h>
#include <nodes/convertnode.h>

class TypeConvertor
{
public:
    static bool isEqual(Type first, Type second);
    static Type getCommonType(Type first, Type second);
    VirtualExprNode *convert(VirtualExprNode* node, Type type);
};

#endif // TYPECOMPARATOR_H
