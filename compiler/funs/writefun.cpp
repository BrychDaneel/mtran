#include "writefun.h"

#include <iostream>
#include <sstream>

WriteFun::WriteFun(SymbolTable *symbolTable)
    : Fun(symbolTable)
{
}

bool WriteFun::canAccept(std::vector<Type> paramsType)
{
    for (Type type : paramsType)
        if (!type.isSimple())
            return false;
    return true;
}

std::string WriteFun::call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal)
{
    std::string code = "";
    for (size_t i=0; i<paramsType.size(); i++){
        switch (paramsType[i].getBaseType()) {
        case BaseType::_boolean:
            code = code + "write_b ";
            break;
        case BaseType::_integer:
            code = code + "write_i ";
            break;
        case BaseType::_real:
            code = code + "write_r ";
            break;
        case BaseType::_char:
            code = code + "write_c ";
            break;
        case BaseType::_string:
            code = code + "write_s ";
            break;
        default:
            break;
        }
        std::stringstream buf;
        if (isLocal[i])
            buf << "$";
        else
            buf << "#";
        buf << params[i];
        buf << "\n";
        code = code + buf.str();
    }
    return code;
}

Type WriteFun::getRetType()
{
    return BaseType::_void;
}

std::string WriteFun::getID()
{
    return "write";
}


