#include "readcharfun.h"

#include <sstream>

ReadCharFun::ReadCharFun(SymbolTable *symbolTable)
    : Fun(symbolTable)
{

}

bool ReadCharFun::canAccept(std::vector<Type> paramsType)
{
    return paramsType.size() == 0;
}

std::string ReadCharFun::call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal)
{
    std::stringstream buf;
    buf << "read_c ";
    if (retIsLocal)
        buf << "$";
    else
        buf << "#";
    buf << ret;

    return buf.str() + "\n";
}

Type ReadCharFun::getRetType()
{
    return BaseType::_char;
}

std::string ReadCharFun::getID()
{
    return "ReadChar";
}

