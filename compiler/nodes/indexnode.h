#ifndef INDEXNODE_H
#define INDEXNODE_H

#include <basenode.h>

class IndexNode : public BaseNode
{
    int adress;
    bool isLocal;
    Type type;
public:
    IndexNode(SymbolTable *symbolTable, int way);
    void setDist(int adress, bool isLocal);
    void setType(Type type);
    std::string getCode() override;
    std::string getName() {return "IndexNode";}
};

#endif // INDEXNODE_H
