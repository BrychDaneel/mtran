#ifndef PROGRAMNODE_H
#define PROGRAMNODE_H

#include <basenode.h>

class ProgramNode : public BaseNode
{
public:
    ProgramNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "ProgramNode";}
    std::string getCode() override;
};

#endif // PROGRAMNODE_H
