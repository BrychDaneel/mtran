#include "varnode.h"
#include <iostream>
#include <tokens/idtoken.h>
#include <nodes/idnode.h>
#include <nodes/callnode.h>
#include <nodes/paramsnode.h>

VarNode::VarNode(SymbolTable* symbolTable, int way)
    : VirtualExprNode(symbolTable, way)
{

}

void VarNode::semantic()
{

    int gid;
    IdInfo* info;
    Signature* sig;
    std::vector<Type> types;

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

            dynamic_cast<CallNode*>(nodes[1]->getNodes()[0])->setGID(gid);
            nodes[1]->semantic();
            break;
        case 2:
            type = Type(info->getType().getBaseType());
            if (info == nullptr){
                std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Unknown array var" << std::endl;
                exit(1);
            }

            if (info->getType().isSimple() && info->getType().getBaseType() != BaseType::_string){
                std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): It is not array" << std::endl;
                exit(1);
            }

            if (info->getType().isSimple() && info->getType().getBaseType() == BaseType::_string){
                types.push_back(BaseType::_integer);
                type = Type(BaseType::_char);
            }
            else
                for (size_t i=0; i<info->getType().getDim().size(); i++)
                    types.push_back(BaseType::_integer);

            dynamic_cast<ParamsNode*>(nodes[1]->getNodes()[0]->getNodes()[1])->setTypes(types);
            nodes[1]->semantic();
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
