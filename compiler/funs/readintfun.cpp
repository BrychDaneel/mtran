#include "readintfun.h"

#include <sstream>

ReadIntFun::ReadIntFun(SymbolTable *symbolTable)
    : Fun(symbolTable)
{

}

bool ReadIntFun::canAccept(std::vector<Type> paramsType)
{
    return paramsType.size() == 0;
}

std::string ReadIntFun::call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal)
{
    std::stringstream buf;
    buf << "read_i ";
    if (retIsLocal)
        buf << "$";
    else
        buf << "#";
    buf << ret;

    return buf.str() + "\n";
}

Type ReadIntFun::getRetType()
{
    return BaseType::_integer;
}

std::string ReadIntFun::getID()
{
    return "ReadInt";
}

