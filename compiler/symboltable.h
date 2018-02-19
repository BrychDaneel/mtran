#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <set>
#include <string>
#include <idinfo.h>

class SymbolTable
{
    int gid=0;
    std::map<std::string, int> globalMap;
    std::vector< std::set<IdInfo> > vis;
public:
    SymbolTable();
    int add(std::string id);
    int getGID(std::string id);

    IdInfo* getInfo(int gid);
    IdInfo* getInfo(std::string id);

    void newVisable();
    void delVisable();

    IdInfo declare(int gid, Type type);
};

#endif // SYMBOLTABLE_H
