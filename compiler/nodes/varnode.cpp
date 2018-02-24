#include "varnode.h"
#include <iostream>
#include <tokens/idtoken.h>
#include <nodes/idnode.h>

VarNode::VarNode(SymbolTable* symbolTable, int way)
    : VirtualExprNode(symbolTable, way)
{

}

void VarNode::semantic()
{

    int gid;
    IdInfo* info;
    Signature* sig;

    switch (way) {

    case 0:
        nodes[0]->semantic();
        gid = dynamic_cast<IdNode*>(nodes[0])->getGID();
        info = symbolTable->getInfo(gid);

        switch (nodes[1]->getWay()){
        case 0:
            if (info == nullptr){
                std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Unknown var" << std::endl;
                exit(1);
            }
            type = info->getType();
            break;
        case 1:
            sig = symbolTable->getSignatyre(gid);
            if (sig == nullptr){
                std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Unknown function" << std::endl;
                exit(1);
            }
            type = sig->getResult();
            if (type.getBaseType() == BaseType::_void){
                std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Procedures don't have result " << std::endl;
                exit(1);
            }
            break;
        case 2:
            type = Type(info->getType().getBaseType());
            if (info == nullptr){
                std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Unknown array var" << std::endl;
                exit(1);
            }
            break;
        default:
            std::cerr << "RUNTIME ERROR: Invalid way" << std::endl;
            exit(1);
        }

        break;
    case 1:
        nodes[0]->semantic();
        type = dynamic_cast<VirtualExprNode*>(nodes[0])->getType();
        break;
    case 2:
        nodes[1]->semantic();
        type = dynamic_cast<VirtualExprNode*>(nodes[1])->getType();
        break;

    default:
        std::cerr << "RUNTIME ERROR: Invalid way" << std::endl;
        exit(1);
        break;
    }
}
