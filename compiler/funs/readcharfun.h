#ifndef READCHARFUN_H
#define READCHARFUN_H

#include <fun.h>

class ReadCharFun : public Fun
{
public:
    ReadCharFun(SymbolTable* symbolTable);
    bool canAccept(std::vector<Type> paramsType) override;
    std::string call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal) override;
    Type getRetType() override;
    std::string getID() override;
};

#endif // READCHARFUN_H
