#ifndef READINTFUN_H
#define READINTFUN_H

#include <fun.h>

class ReadIntFun : public Fun
{
public:
    ReadIntFun(SymbolTable* symbolTable);
    bool canAccept(std::vector<Type> paramsType) override;
    std::string call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal) override;
    Type getRetType() override;
    std::string getID() override;
};

#endif // READINTFUN_H
