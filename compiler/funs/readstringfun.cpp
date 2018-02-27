#include "readstringfun.h"

#include <sstream>

ReadStringFun::ReadStringFun(SymbolTable *symbolTable)
    : Fun(symbolTable)
{

}

bool ReadStringFun::canAccept(std::vector<Type> paramsType)
{
    return paramsType.size() == 0;
}

std::string ReadStringFun::call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal)
{
    std::stringstream buf;
    buf << "read_s ";
    if (retIsLocal)
        buf << "$";
    else
        buf << "#";
    buf << ret;

    return buf.str() + "\n";
}

Type ReadStringFun::getRetType()
{
    return BaseType::_string;
}

std::string ReadStringFun::getID()
{
    return "ReadString";
}

