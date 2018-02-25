#include "symboltable.h"

#include <iostream>
#include <algorithm>

SymbolTable::SymbolTable()
{
    vis.push_back(std::vector<IdInfo>());
}

int SymbolTable::add(std::string id)
{
    std::transform(id.begin(), id.end(), id.begin(), tolower);
    if (globalMap.find(id) != globalMap.end()){
        std::cerr << "Symbol allready in table" << std::endl;
        exit(1);
    }
    globalMap[id] = gid;
    return gid++;
}

int SymbolTable::getGID(std::string id)
{
    std::transform(id.begin(), id.end(), id.begin(), tolower);
    if (globalMap.find(id) == globalMap.end())
        add(id);

    return globalMap[id];
}

IdInfo *SymbolTable::getInfo(int gid)
{
    for (int i=visTop; i>=0; i--)
        for (size_t ii=0; ii<vis[i].size(); ii++)
            if (vis[i][ii].getGId() == gid)
                return &vis[i][ii];

    return nullptr;
}

IdInfo *SymbolTable::getInfo(std::string id)
{
    std::transform(id.begin(), id.end(), id.begin(), tolower);
    int gid = getGID(id);
    if (gid == -1)
        return nullptr;

    return getInfo(gid);
}

void SymbolTable::startFunction(Type retType)
{
    vis.push_back(std::vector<IdInfo>());
    visTop++;
    retTypes.push_back(retType);
}

void SymbolTable::endFunction()
{
    vis.pop_back();
    if (!vis.size()){
        std::cerr << "Can't delete global visable area!" << std::endl;
        exit(1);
    }

    retTypes.pop_back();
    visTop --;
}

Type SymbolTable::getReturnType()
{
    return retTypes[retTypes.size() - 1];
}

bool SymbolTable::isLocal()
{
    return retTypes.size() > 1;
}

IdInfo* SymbolTable::define(int gid, Type type)
{
    vis[visTop].push_back(IdInfo(gid, type, top[visTop], visTop > 0));
    top[visTop] += type.getSize();
    return &vis[visTop][gid];
}

void SymbolTable::addFunction(int gid, Signature sig)
{
    if (funs.find(gid) != funs.end()){
        std::cerr << "Function allready in table" << std::endl;
        exit(1);
    }
    funs[gid] = sig;
}

Signature* SymbolTable::getSignatyre(int gid)
{
    if (funs.find(gid) == funs.end())
        return nullptr;
    return &funs[gid];
}

void SymbolTable::startLoop(int loopStart, int loopEnd, int loopContinue)
{
    loopsStart.push_back(loopStart);
    loopsEnd.push_back(loopEnd);
    loopsContinue.push_back(loopContinue);
}

void SymbolTable::endLoop()
{
    loopsStart.pop_back();
    loopsEnd.pop_back();
    loopsContinue.pop_back();
}

void SymbolTable::getLoopInfo(int &loopStart, int &loopEnd, int &loopContinue)
{
    if (loopsStart.size() == 0){
        loopStart = -1;
        loopEnd = -1;
        loopContinue = -1;
        return;
    }

    loopStart = loopsStart[loopsStart.size()];
    loopEnd = loopsEnd[loopsEnd.size()];
    loopContinue = loopsContinue[loopsContinue.size()];
}
