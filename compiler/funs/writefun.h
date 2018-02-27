#ifndef WRITEFUN_H
#define WRITEFUN_H

#include <fun.h>

class WriteFun : public Fun
{
public:
    WriteFun(SymbolTable* symbolTable);
    bool canAccept(std::vector<Type> paramsType) override;
    std::string call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal) override;
    Type getRetType() override;
    std::string getID() override;
};

#endif // WRITEFUN_H
