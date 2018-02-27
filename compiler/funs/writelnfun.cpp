#include "writelnfun.h"

#include <sstream>

WriteLnFun::WriteLnFun(SymbolTable *symbolTable)
    : WriteFun(symbolTable)
{

}

std::string WriteLnFun::call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal)
{
    std::stringstream buf;
    buf << this->WriteFun::call(paramsType, params, isLocal, ret, retIsLocal);
    int adr = symbolTable->getAdress();
    buf << "push 1\n";
    buf << "load_i $" << adr << " 10\n";
    buf << "write_c $"<< adr << "\n";
    buf << "pop 1\n";

    return buf.str();
}

std::string WriteLnFun::getID()
{
    return "writeln";
}
