#ifndef BASENODE_H
#define BASENODE_H

#include <node.h>
#include <vector>
#include <symboltable.h>

class BaseNode : public Node
{
protected:
    int way = -1;
    std::vector<Node*> nodes;
    std::string code;
    SymbolTable* symbolTable;

public:
    BaseNode();
    BaseNode(SymbolTable* symbolTable, int way);
    void add(Node* node);
    void print(int level=0);
    void semantic();
    std::string getCode();
    void emitCode(std::string c);
    std::string getName() {return "BaseNode";}
    SymbolTable* getSymbolTable();
    int getWay();
    std::vector<Node*> getNodes();
    int getLine() override;
    int getPos() override;
};

#endif // BASENODE_H
