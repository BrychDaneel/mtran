#include "symboltable.h"

#include <iostream>
#include <algorithm>

#include <funs/writefun.h>
#include <funs/writelnfun.h>
#include <funs/readintfun.h>
#include <funs/readrealfun.h>
#include <funs/readcharfun.h>
#include <funs/readstringfun.h>

SymbolTable::SymbolTable()
{
    vis.push_back(std::vector<IdInfo>());

    Fun* fun;
    int gid;

    fun = new WriteFun(this);
    gid = add(fun->getID());
    buildInFuns[gid] = fun;

    fun = new WriteLnFun(this);
    gid = add(fun->getID());
    buildInFuns[gid] = fun;

    fun = new ReadIntFun(this);
    gid = add(fun->getID());
    buildInFuns[gid] = fun;

    fun = new ReadRealFun(this);
    gid = add(fun->getID());
    buildInFuns[gid] = fun;

    fun = new ReadCharFun(this);
    gid = add(fun->getID());
    buildInFuns[gid] = fun;

    fun = new ReadStringFun(this);
    gid = add(fun->getID());
    buildInFuns[gid] = fun;

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

void SymbolTable::startFunction(int gid, std::vector<int> paramsID, Type retType)
{
    vis.push_back(std::vector<IdInfo>());
    visTop++;
    retTypes.push_back(retType);
    top.push_back(0);
    funsGID.push_back(gid);
    this->paramsID.push_back(paramsID);
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
    top.pop_back();
    funsGID.pop_back();
    this->paramsID.pop_back();
}

Type SymbolTable::getReturnType()
{
    return retTypes[retTypes.size() - 1];
}

int SymbolTable::getFunGID()
{
    return funsGID[funsGID.size()-1];
}

std::vector<int> SymbolTable::getParamsID()
{
    return paramsID[paramsID.size()-1];
}

bool SymbolTable::isLocal()
{
    return retTypes.size() > 1;
}

IdInfo* SymbolTable::define(int gid, Type type)
{
    vis[visTop].push_back(IdInfo(gid, type, -1, visTop > 0));
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

void SymbolTable::startLoop(int loopStart, int loopEnd, int loopContinue, int loopAdress)
{
    loopsStart.push_back(loopStart);
    loopsEnd.push_back(loopEnd);
    loopsContinue.push_back(loopContinue);
    loopsAdress.push_back(loopAdress);
}

void SymbolTable::endLoop()
{
    loopsStart.pop_back();
    loopsEnd.pop_back();
    loopsContinue.pop_back();
    loopsAdress.pop_back();
}

void SymbolTable::getLoopInfo(int &loopStart, int &loopEnd, int &loopContinue, int &loopAdress)
{
    if (loopsStart.size() == 0){
        loopStart = -1;
        loopEnd = -1;
        loopContinue = -1;
        loopAdress = -1;
        return;
    }

    loopStart = loopsStart[loopsStart.size() - 1];
    loopEnd = loopsEnd[loopsEnd.size() - 1];
    loopContinue = loopsContinue[loopsContinue.size() - 1];
    loopAdress = loopsAdress[loopsAdress.size() - 1];
}

Fun *SymbolTable::getBuidIn(int gid)
{
    if (buildInFuns.find(gid) == buildInFuns.end())
        return nullptr;

    return buildInFuns[gid];
}

void SymbolTable::push(int size)
{
    top[visTop] += size;
}

void SymbolTable::pop(int size)
{
    top[visTop] -= size;
}

int SymbolTable::getAdress()
{
    return top[visTop];
}

int SymbolTable::getLabel()
{
    return label++;
}

void SymbolTable::addCallLabel(int gid, int lab)
{
    funsAdress[gid] = lab;
}

int SymbolTable::getCallLabel(int gid)
{
    return funsAdress[gid];
}

void SymbolTable::clearGlobVis()
{
    while (vis[0].size()>0)
        vis[0].pop_back();
}

std::vector<IdInfo *> SymbolTable::getThisVisable()
{
    std::vector<IdInfo*> res;
    for (IdInfo& info : vis[visTop])
        res.push_back(&info);
    return res;
}
