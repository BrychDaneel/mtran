#ifndef BINARNODE_H
#define BINARNODE_H

#include <nodes/virtualexprnode.h>

class BinarNode : public VirtualExprNode
{
    Type right;

    int operPos;
    int operLine;
    Type left;
    bool hasLeft = false;

    bool first;

    enum OpType {_div, _mod, _mult, _rdiv, _plus, _minus,  _and, _or, _xor, _ce, _cne, _ca, _cb, _cae, _cbe} opType;

    OpType getOperationType();
    void perfome();

public:
    BinarNode(SymbolTable *symbolTable, int way, bool first);
    std::string getName() override {return "BinarNode";}
    void semantic() override;
    void setLeftType(Type type);
    void setLeftOpType(OpType opType);
    void setOperLine(int line);
    void setOperPos(int pos);

};

#endif // COMPARENODE_H
