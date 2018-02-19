#include "symboltable.h"

#include <iostream>

SymbolTable::SymbolTable()
{

}

int SymbolTable::add(std::string id)
{
    globalMap[id] = gid;
    return gid++;
}

int SymbolTable::getGID(std::string id)
{
    if (globalMap.find(id) == globalMap.end())
        return -1;
    return globalMap[id];
}

IdInfo *SymbolTable::getInfo(int gid)
{

}

IdInfo *SymbolTable::getInfo(std::string id)
{
    int gid = getGID(id);
    if (gid == -1)
        return nullptr;

    return getInfo(gid);
}

void SymbolTable::newVisable()
{
    vis.push_back(std::set<IdInfo>());
}

void SymbolTable::delVisable()
{
    vis.pop_back();
    if (!vis.size()){
        std::cerr << "Can't delete global visable area!" << std::endl;
        exit(1);
    }
}

IdInfo SymbolTable::declare(int gid, Type type)
{

}
