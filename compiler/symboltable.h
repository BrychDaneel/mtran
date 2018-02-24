#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <set>
#include <string>
#include <idinfo.h>
#include <signature.h>
#include <map>

class SymbolTable
{
    int gid=0;
    std::map<std::string, int> globalMap;
    std::vector< std::vector<IdInfo> > vis;
    std::vector< Type > retTypes;
    std::vector<int> top = {100};
    int visTop=0;

    std::map<int, Signature> funs;

    std::vector<int> loopsStart, loopsEnd, loopsContinue;

public:
    SymbolTable();
    int add(std::string id);
    int getGID(std::string id);

    IdInfo* getInfo(int gid);
    IdInfo* getInfo(std::string id);

    void startFunction(Type retType);
    void endFunction();
    Type getReturnType();
    bool isLocal();

    IdInfo* define(int gid, Type type);

    void addFunction(int gid, Signature sig);
    Signature* getSignatyre(int gid);

    void startLoop(int loopStart, int loopEnd, int loopContinue);
    void EndLoop();
    void getLoopInfo(int& loopStart, int& loopEnd, int& loopContinue);

};

#endif // SYMBOLTABLE_H
