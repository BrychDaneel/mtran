#include "readrealfun.h"

#include <sstream>

ReadRealFun::ReadRealFun(SymbolTable *symbolTable)
    : Fun(symbolTable)
{

}

bool ReadRealFun::canAccept(std::vector<Type> paramsType)
{
    return paramsType.size() == 0;
}

std::string ReadRealFun::call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal)
{
    std::stringstream buf;
    buf << "read_r ";
    if (retIsLocal)
        buf << "$";
    else
        buf << "#";
    buf << ret;

    return buf.str() + "\n";
}

Type ReadRealFun::getRetType()
{
    return BaseType::_real;
}

std::string ReadRealFun::getID()
{
    return "ReadReal";
}

