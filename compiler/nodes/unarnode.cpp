#include "unarnode.h"

#include <tokens/sumtoken.h>
#include <nodes/terminalnode.h>
#include <typeconvertor.h>

#include <iostream>
#include <sstream>

UnarNode::UnarNode(SymbolTable *symbolTable, int way)
    :VirtualExprNode(symbolTable, way)
{

}


void UnarNode::semantic()
{
    nodes[1]->semantic();

    if (nodes[0]->getWay() == 1)
        subType = SubType::_not;
    else{
        TerminalNode* node = dynamic_cast<TerminalNode*>(nodes[0]->getNodes()[0]);
        SumToken* token = dynamic_cast<SumToken*>(node->getToken());
        if (token->getSubType() == SumToken::SubType::minus)
            subType = SubType::_minus;
        else
            subType = SubType::_plus;
    }

    VirtualExprNode* expr = dynamic_cast<VirtualExprNode*>(nodes[1]);
    Type type = expr->getType();

    if (!type.isSimple()){
        std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Can't perfom operation to array" << std::endl;
        exit(1);
    }

    if (subType == SubType::_not &&
            type.getBaseType() != BaseType::_integer && type.getBaseType() != BaseType::_boolean){
        std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Bad type for not operator" << std::endl;
        exit(1);
    }
    if (subType != SubType::_not &&
            type.getBaseType() != BaseType::_real && type.getBaseType() != BaseType::_integer){
        std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Bad type for not operator" << std::endl;
        exit(1);
    }

    this->type = type;

}

std::string UnarNode::getCode()
{
    code = "";
    std::stringstream buf;

    VirtualExprNode* expr = dynamic_cast<VirtualExprNode*>(nodes[1]);
    expr->setDist(dist, isLocal);
    code = code + expr->getCode();

    buf.str("");
    if (isLocal)
        buf << "$";
    else
        buf << "#";
    buf << dist;

    std::string sAdr = buf.str();

    switch (type.getBaseType()) {
    case BaseType::_integer:
        switch (subType) {
        case SubType::_minus :
            emitCode("iminus " + sAdr);
            break;
        case SubType::_plus :
            break;
        case SubType::_not :
            emitCode("inot " + sAdr);
            break;
        }
        break;
    case BaseType::_real:
        switch (subType) {
        case SubType::_minus :
            emitCode("rminus " + sAdr);
            break;
        case SubType::_plus :
            break;
        }
    case BaseType::_boolean:
        switch (subType) {
        case SubType::_not :
            emitCode("bnot " + sAdr);
            break;
        }
    }

    return code;
}
