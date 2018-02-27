#ifndef IDINSTRNODE_H
#define IDINSTRNODE_H


#include <basenode.h>


class IdInstrNode : public BaseNode
{
protected:
    bool start;
    int gid;
    enum SubType {var, array, string, fun} subType;
public:
    IdInstrNode(SymbolTable *symbolTable, int way, bool start);
    void setGID(int gid);
    std::string getName() {return "IdInstrNode";}
    void semantic();
    std::string getCode() override;
};

#endif // IDINSTRNODE_H
