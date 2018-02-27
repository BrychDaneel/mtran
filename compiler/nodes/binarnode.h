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
    int leftAdress;
    bool isLeftLocal;
    bool first;
    bool isEq;

    enum OpType {_div, _mod, _mult, _rdiv, _plus, _minus,  _and, _or, _xor, _ce, _cne, _ca, _cb, _cae, _cbe} opType;

    OpType getOperationType();
    void perfome();

public:
    BinarNode(SymbolTable *symbolTable, int way, bool first, bool isEq=false);
    std::string getName() override {return "BinarNode";}
    void semantic() override;
    void setLeftType(Type type);
    void setLeftAdress(int adress, bool isLocal);
    void setLeftOpType(OpType opType);
    void setOperLine(int line);
    void setOperPos(int pos);

    std::string getOpCode(int retAdress, int leftAdress, int rightAdress, Type type);
    std::string getCode() override;
};

#endif // COMPARENODE_H
