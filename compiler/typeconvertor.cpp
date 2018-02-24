#include "typeconvertor.h"



bool TypeConvertor::isEqual(Type first, Type second)
{
    if (first.getBaseType() != second.getBaseType())
        return false;

    if (first.getDim().size() != second.getDim().size())
        return false;

    for (size_t i=0; i<first.getDim().size(); i++){
        if (first.getDim()[i] != second.getDim()[i])
            return false;
        if (first.getStart()[i] != second.getStart()[i])
            return false;
    }

    return true;
}

Type TypeConvertor::getCommonType(Type first, Type second)
{
    if (isEqual(first, second))
        return first;

    if (first.getDim().size()>0 || second.getDim().size()>0)
        return Type(BaseType::_void);

    if  (
         (first.getBaseType() == BaseType::_integer && second.getBaseType() == BaseType::_real) ||
         (first.getBaseType() == BaseType::_real && second.getBaseType() == BaseType::_integer)
        )
        return Type(BaseType::_real);

    if  (
         (first.getBaseType() == BaseType::_string && second.getBaseType() == BaseType::_char) ||
         (first.getBaseType() == BaseType::_char && second.getBaseType() == BaseType::_string)
        )
        return Type(BaseType::_string);

    return Type(BaseType::_void);
}

VirtualExprNode *TypeConvertor::convert(VirtualExprNode *node, Type type)
{
    if (isEqual(node->getType(), type))
        return node;
    return new ConvertNode(node->getSymbolTable(), node, type);
}
