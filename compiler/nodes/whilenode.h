#ifndef WHILENODE_H
#define WHILENODE_H

#include <basenode.h>

class WhileNode : public BaseNode
{
public:
    WhileNode(SymbolTable *symbolTable, int way);
    std::string getName() {return "WhileNode";}
    void semantic();
    std::string getCode() override;
};

#endif // WHILENODE_H
