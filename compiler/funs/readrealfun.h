#ifndef READREALFUN_H
#define READREALFUN_H

#include <fun.h>

class ReadRealFun : public Fun
{
public:
    ReadRealFun(SymbolTable* symbolTable);
    bool canAccept(std::vector<Type> paramsType) override;
    std::string call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal) override;
    Type getRetType() override;
    std::string getID() override;
};

#endif // READREALFUN_H
