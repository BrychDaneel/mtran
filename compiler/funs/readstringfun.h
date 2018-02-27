#ifndef READSTRINGFUN_H
#define READSTRINGFUN_H

#include <fun.h>

class ReadStringFun : public Fun
{
public:
    ReadStringFun(SymbolTable* symbolTable);
    bool canAccept(std::vector<Type> paramsType) override;
    std::string call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal) override;
    Type getRetType() override;
    std::string getID() override;
};

#endif // READSTRINGFUN_H
