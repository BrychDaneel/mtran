#ifndef WRITELNFUN_H
#define WRITELNFUN_H

#include <funs/writefun.h>

class WriteLnFun : public WriteFun
{
public:
    WriteLnFun(SymbolTable* symbolTable);
    std::string call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal) override;
    std::string getID() override;
};

#endif // WRITELNFUN_H
