#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <set>
#include <string>
#include <idinfo.h>
#include <signature.h>
#include <map>

#include <fun.h>

class Fun;

class SymbolTable
{
    int gid=0;
    std::map<std::string, int> globalMap;
    std::vector< std::vector<IdInfo> > vis;
    std::vector< Type > retTypes = {BaseType::_integer};
    std::vector<int> top = {1};
    std::vector<int> funsGID;
    std::map<int,int> funsAdress;
    int visTop=0;

    std::map<int, Signature> funs;

    std::vector<int> loopsStart, loopsEnd, loopsContinue, loopsAdress;

    std::map<int, Fun*> buildInFuns;

    std::vector<std::vector<int> > paramsID;

    int label=0;

public:
    SymbolTable();
    int add(std::string id);
    int getGID(std::string id);

    IdInfo* getInfo(int gid);
    IdInfo* getInfo(std::string id);

    void startFunction(int gid, std::vector<int> paramsID, Type retType);
    void endFunction();
    Type getReturnType();
    int getFunGID();
    std::vector<int> getParamsID();
    bool isLocal();

    IdInfo* define(int gid, Type type);

    void addFunction(int gid, Signature sig);
    Signature* getSignatyre(int gid);

    void startLoop(int loopStart, int loopEnd, int loopContinue, int loopAdress);
    void endLoop();
    void getLoopInfo(int& loopStart, int& loopEnd, int& loopContinue, int& loopAdress);

    Fun* getBuidIn(int gid);

    void push(int size);
    void pop(int size);
    int getAdress();

    int getLabel();

    void addCallLabel(int gid, int lab);
    int getCallLabel(int gid);

    void clearGlobVis();

    std::vector<IdInfo*> getThisVisable();
};

#endif // SYMBOLTABLE_H
