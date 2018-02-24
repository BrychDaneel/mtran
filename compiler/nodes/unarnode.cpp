#include "unarnode.h"

#include <tokens/sumtoken.h>
#include <nodes/terminalnode.h>
#include <typeconvertor.h>

#include <iostream>

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
        TerminalNode* node = dynamic_cast<TerminalNode*>(nodes[0]);
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
