#include "literalnode.h"

#include <iostream>
#include <sstream>
#include <tokens/integertoken.h>
#include <tokens/realtoken.h>
#include <tokens/stringtoken.h>
#include <tokens/chartoken.h>
#include <nodes/terminalnode.h>

LiteralNode::LiteralNode(SymbolTable* symbolTable, int way)
    :VirtualExprNode(symbolTable, way)
{
}

void LiteralNode::semantic()
{
switch (way) {
case 0:
    type = Type(BaseType::_integer);
    break;
case 1:
    type = Type(BaseType::_real);
    break;
case 2:
    type = Type(BaseType::_char);
    break;
case 3:
    type = Type(BaseType::_string);
    break;
case 4:
    type = Type(BaseType::_boolean);
    break;
case 5:
    type = Type(BaseType::_boolean);
    break;
default:
    std::cerr << "Invalid way." << std::endl;
    break;
}

}

std::string LiteralNode::getCode()
{
    code = "";
    std::stringstream buf;

    switch (way) {
    case 0:
        buf << "load_i ";
        buf << strAdress();
        buf << " ";
        buf << dynamic_cast<IntegerToken*>(dynamic_cast<TerminalNode*>(nodes[0])->getToken())->getValue();
        break;
    case 1:
        buf << "load_r ";
        buf << strAdress();
        buf << " ";
        buf << dynamic_cast<RealToken*>(dynamic_cast<TerminalNode*>(nodes[0])->getToken())->getValue();
        break;
    case 2:
        buf << "load_i ";
        buf << strAdress();
        buf << " ";
        buf << (int)dynamic_cast<CharToken*>(dynamic_cast<TerminalNode*>(nodes[0])->getToken())->getValue();
        break;
    case 3:
        buf << "load_s ";
        buf << strAdress();
        buf << " ";
        buf << dynamic_cast<StringToken*>(dynamic_cast<TerminalNode*>(nodes[0])->getToken())->getValue();
        break;
    case 4:
        buf << "load_i ";
        buf << strAdress();
        buf << " 1";
        break;
    case 5:
        buf << "load_i ";
        buf << strAdress();
        buf << " 0";
        break;
    }

    emitCode(buf.str());
    return code;
}
