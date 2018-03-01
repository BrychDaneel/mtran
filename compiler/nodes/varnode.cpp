#include "varnode.h"
#include <iostream>
#include <tokens/idtoken.h>
#include <nodes/idnode.h>
#include <nodes/callnode.h>
#include <nodes/paramsnode.h>
#include <nodes/indexnode.h>

#include <sstream>

VarNode::VarNode(SymbolTable* symbolTable, int way)
    : VirtualExprNode(symbolTable, way)
{

}

void VarNode::semantic()
{

    IdInfo* info;
    std::vector<Type> types;
    CallNode* callNode;

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
            subType = SubType::_var;
            break;
        case 1:

            callNode = dynamic_cast<CallNode*>(nodes[1]->getNodes()[0]);
            callNode->setGID(gid);
            nodes[1]->semantic();

            type = callNode->getRetType();
            if (type.getBaseType() == BaseType::_void){
                std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Procedures don't have result " << std::endl;
                exit(1);
            }
            subType = SubType::_fun;
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

            if (info->getType().isSimple())
                subType = SubType::_string;
            else
                subType = SubType::_array;
            break;
        default:
            std::cerr << "RUNTIME ERROR: Invalid way" << std::endl;
            exit(1);
        }

        break;
    case 1:
        nodes[0]->semantic();
        type = dynamic_cast<VirtualExprNode*>(nodes[0])->getType();
        subType = SubType::_literal;
        break;
    case 2:
        nodes[1]->semantic();
        type = dynamic_cast<VirtualExprNode*>(nodes[1])->getType();
        subType = SubType::_expr;
        break;

    default:
        std::cerr << "RUNTIME ERROR: Invalid way" << std::endl;
        exit(1);
        break;
    }
}

std::string VarNode::getCode()
{
    std::stringstream buf;
    code = "";
    IdInfo* info;
    VirtualExprNode* exprNode;
    int adrAdr;

    switch (subType) {
    case SubType::_literal:
        exprNode = dynamic_cast<VirtualExprNode*>(nodes[0]);
        exprNode->setDist(dist, isLocal);
        return exprNode->getCode();
    case SubType::_var:
        info = symbolTable->getInfo(gid);
        buf.str("");
        buf << "mov " << info->getType().getSize() << " ";
        if (isLocal)
            buf << "$";
        else
            buf << "#";
        buf << dist << " ";

        if (info->isLocal())
            buf << "$";
        else
            buf << "#";
        buf << info->getAdress();

        emitCode(buf.str());
        break;
    case SubType::_expr:
        exprNode = dynamic_cast<VirtualExprNode*>(nodes[1]);
        exprNode->setDist(dist, isLocal);
        return exprNode->getCode();
    case SubType::_array:
        {
        info = symbolTable->getInfo(gid);
        adrAdr = symbolTable->getAdress();
        emitCode("push 1");
        symbolTable->push(1);
        buf.str("");
        buf << "load_i " << "$" << adrAdr << " " << info->getAdress();
        if (!info->getType().isSimple())
            emitCode(buf.str());

        IndexNode* indNode = dynamic_cast<IndexNode*>(nodes[1]->getNodes()[0]);
        indNode->setDist(adrAdr, true);
        if (!info->getType().isSimple())
            indNode->setType(info->getType());
        else
            indNode->setType(Type(BaseType::_char, {0}, {255}));

        code = code + indNode->getCode();

        buf.str("");
        buf << "mov " << type.getSize() << " ";
        if (isLocal)
            buf << "$";
        else
            buf << "#";
        buf << dist << " ";

        buf << "?$" << adrAdr;
        emitCode(buf.str());

        emitCode("pop 1");
        symbolTable->pop(1);
        }
        break;

    case SubType::_string:
        {

        info = symbolTable->getInfo(gid);
        adrAdr = symbolTable->getAdress();
        emitCode("push 1");

        symbolTable->push(1);
        buf.str("");
        buf << "load_i " << "$" << adrAdr<< " " << 0;
        emitCode(buf.str());

        IndexNode* indNode = dynamic_cast<IndexNode*>(nodes[1]->getNodes()[0]);
        indNode->setDist(adrAdr, true);
        indNode->setType(Type(BaseType::_char, {1}, {256}));
        code = code + indNode->getCode();

        buf.str("");
        buf << "mov_from_s ";
        if (isLocal)
            buf << "$";
        else
            buf << "#";
        buf << dist << " ";

        if (info->isLocal())
            buf << "$";
        else
            buf << "#";
        buf << info->getAdress() << " ";

        buf << "?$" << adrAdr;
        emitCode(buf.str());

        emitCode("pop 1");
        symbolTable->pop(1);
        }
        break;

    case SubType::_fun:
        CallNode* callNode = dynamic_cast<CallNode*>(nodes[1]->getNodes()[0]);
        callNode->setDist(dist, isLocal);
        return callNode->getCode();
    }

    return code;
}
