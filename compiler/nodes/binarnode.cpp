#include "binarnode.h"

#include <nodes/terminalnode.h>
#include <tokens/sumtoken.h>
#include <tokens/eqtoken.h>
#include <tokens/idtoken.h>
#include <tokens/facttoken.h>
#include <keywordsfactory.h>
#include <tokens/keywordtoken.h>

#include <typeconvertor.h>

#include <iostream>

BinarNode::OpType BinarNode::getOperationType()
{
    TerminalNode* node = dynamic_cast<TerminalNode*>(nodes[0]);
    if (!node)
        node = dynamic_cast<TerminalNode*>(nodes[0]->getNodes()[0]);

    Token* token = node->getToken();

    if (token->getType() == SumToken::TYPE)
        switch (dynamic_cast<SumToken*>(token)->getSubType()) {
        case SumToken::SubType::minus:
            return OpType::_minus;
        case SumToken::SubType::plus:
            return OpType::_plus;
        }

    if (token->getType() == EQToken::TYPE)
        switch (dynamic_cast<EQToken*>(token)->getSubType()) {
        case EQToken::SubType::ce:
            return OpType::_ce;
        case EQToken::SubType::cne:
            return OpType::_cne;
        case EQToken::SubType::ca:
            return OpType::_ca;
        case EQToken::SubType::cb:
            return OpType::_cb;
        case EQToken::SubType::cae:
            return OpType::_cae;
        case EQToken::SubType::cbe:
            return OpType::_cbe;
        }

    if (token->getType() == KeywordsFactory::getId("and"))
        return opType = OpType::_and;
    if (token->getType() == KeywordsFactory::getId("or"))
        return opType = OpType::_or;
    if (token->getType() == KeywordsFactory::getId("xor"))
        return opType = OpType::_xor;

    if (token->getType() == KeywordsFactory::getId("div"))
        return opType = OpType::_div;
    if (token->getType() == KeywordsFactory::getId("mod"))
        return opType = OpType::_mod;


    if (token->getType() == FactToken::TYPE)
        switch (dynamic_cast<FactToken*>(token)->getSubType()) {
        case FactToken::SubType::div:
            return OpType::_rdiv;
        case FactToken::SubType::mult:
            return OpType::_mult;
        }

    std::cerr << "RUNTIME ERRROR while process bin op." << std::endl;
    exit(1);
}

BinarNode::BinarNode(SymbolTable *symbolTable, int way, bool first)
    : VirtualExprNode(symbolTable, way)
{
    this->first = first;
}

void BinarNode::semantic()
{
    if (!first){
        if (!hasLeft){
            std::cerr << "RUNTIME ERRROR while process bin op." << std::endl;
            exit(1);
        }

        BinarNode* rightNode = dynamic_cast<BinarNode*>(nodes[1]);
        rightNode->setLeftOpType(getOperationType());
        rightNode->setLeftType(left);
        rightNode->setOperLine(getLine());
        rightNode->setOperPos(getPos());

        nodes[1]->semantic();
        this->type = rightNode->getType();
        return;
    }


    nodes[0]->semantic();
    right = dynamic_cast<VirtualExprNode*>(nodes[0])->getType();


    if (hasLeft)
        perfome();
    else
        type = right;


    if (nodes[1]->getWay() == 0)
        return;
    dynamic_cast<BinarNode*>(nodes[1])->setLeftType(type);
    nodes[1]->semantic();
    type = dynamic_cast<BinarNode*>(nodes[1])->getType();
}

void BinarNode::setLeftType(Type type)
{
    hasLeft = true;
    left = type;
}

void BinarNode::setLeftOpType(BinarNode::OpType opType)
{
    this->opType = opType;
}

void BinarNode::setOperLine(int line)
{
    operLine = line;
}

void BinarNode::setOperPos(int pos)
{
    operPos = pos;
}


void BinarNode::perfome()
{
    Type commonType = TypeConvertor::getCommonType(left, right);

    if (!commonType.isSimple()) {
        std::cerr << "SEMANTIC ERROR(" << operLine << "," << operPos << "): Y can't do it width array" << std::endl;
        exit(1);
    }

    if (commonType.getBaseType() == BaseType::_void){
        std::cerr << "SEMANTIC ERROR(" << operLine << "," << operPos << "): Types incompatible" << std::endl;
        exit(1);
    }

    if (opType == OpType::_ca || opType == OpType::_cb || opType == OpType::_cae ||
        opType == OpType::_cbe)
        if (commonType.getBaseType() != BaseType::_integer && commonType.getBaseType() != BaseType::_real){
            std::cerr << "SEMANTIC ERROR(" << operLine << "," << operPos << "): Uncomparable types" << std::endl;
            exit(1);
        }

    if (commonType.getBaseType() == BaseType::_boolean &&
            (opType != OpType::_ce && opType != OpType::_cne
             && opType != OpType::_or && opType != OpType::_xor && opType != OpType::_and) )
    {
        std::cerr << "SEMANTIC ERROR(" << operLine << "," << operPos << "): You can't do it with boolean" << std::endl;
        exit(1);
    }

    if ((commonType.getBaseType() == BaseType::_string || commonType.getBaseType() == BaseType::_char) &&
            (opType != OpType::_ce && opType != OpType::_cne && opType != OpType::_plus) )
    {
        std::cerr << "SEMANTIC ERROR(" << operLine << "," << operPos << "): Invalid string operation" << std::endl;
        exit(1);
    }


    if (opType == OpType::_ca || opType == OpType::_cb || opType == OpType::_cae ||
            opType == OpType::_cbe || opType == OpType::_ce || opType == OpType::_cne)

        type = Type(BaseType::_boolean);
    else
        type = commonType;
}

