#include "typenode.h"

#include <nodes/terminalnode.h>
#include <nodes/dimnode.h>
#include <tokens/idtoken.h>

#include <iostream>

TypeNode::TypeNode(SymbolTable *symbolTable, int way)
    : BaseNode(symbolTable, way)
{
    this->symbolTable = symbolTable;
    this->way = way;
}

void TypeNode::semantic()
{

    int idIndex = 0;
    if (way == 1){
        idIndex = 5;
    }

    IdToken* token = dynamic_cast<IdToken*>(dynamic_cast<TerminalNode*>(nodes[idIndex])->getToken());
    std::string typeName = token->getLowerLexem();

    BaseType base = BaseType::_void;

    if (typeName == "real" || typeName == "extended")
        base = BaseType::_real;
    else if (typeName == "longint" || typeName == "integer")
        base = BaseType::_integer;
    else if (typeName == "string")
        base = BaseType::_string;
    else if (typeName == "char")
        base = BaseType::_char;
    else if (typeName == "boolean")
        base = BaseType::_boolean;
    else{
        std::cerr << "SEMANTIC ERORR(" << getLine() << "," << getPos() << "): Unknown type" << std::endl;
        exit(1);
    }

    if (way == 0){
        type = Type(base);
        return;
    }

    nodes[2]->semantic();
    DimNode* dimNode = dynamic_cast<DimNode*>(nodes[2]);

    type = Type(base, dimNode->getStart(), dimNode->getDimSize());
}

Type TypeNode::getType()
{
    return type;
}
