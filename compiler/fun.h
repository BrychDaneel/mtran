#ifndef FUN_H
#define FUN_H

#include <vector>
#include <idinfo.h>
#include <type.h>

#include <symboltable.h>

class SymbolTable;

class Fun
{
protected:
    SymbolTable* symbolTable;
public:
    Fun(SymbolTable* symbolTable);
    virtual bool canAccept(std::vector<Type> paramsType) = 0;
    virtual std::string call(std::vector<Type> paramsType, std::vector<int> params, std::vector<bool> isLocal, int ret, bool retIsLocal) = 0;
    virtual Type getRetType() = 0;
    virtual std::string getID() = 0;
};

#endif // FUN_H
