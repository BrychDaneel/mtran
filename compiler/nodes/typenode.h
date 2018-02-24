#ifndef TYPENODE_H
#define TYPENODE_H

#include <basenode.h>

class TypeNode : public BaseNode
{
    Type type;
public:
    TypeNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "TypeNode";}
    void semantic();
    Type getType();
};

#endif // TYPENODE_H
