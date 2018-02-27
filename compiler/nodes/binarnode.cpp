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

#include <sstream>

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

BinarNode::BinarNode(SymbolTable *symbolTable, int way, bool first, bool isEq)
    : VirtualExprNode(symbolTable, way)
{
    this->first = first;
    this->isEq = isEq;
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

void BinarNode::setLeftAdress(int adress, bool isLocal)
{
    this->leftAdress = adress;
    this->isLeftLocal = isLocal;
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

std::string BinarNode::getOpCode(int retAdress, int leftAdress, int rightAdress, Type type)
{
    std::stringstream buf;

    if (type.getBaseType() == BaseType::_real)
        switch (opType) {
        case OpType::_plus:
            buf << "radd";
            break;
        case OpType::_minus:
            buf << "rsub";
            break;
        case OpType::_rdiv:
            buf << "rdiv";
            break;
        case OpType::_mult:
            buf << "rmull";
            break;
        case OpType::_ca:
            buf << "rca";
            break;
        case OpType::_cb:
            buf << "rcb";
            break;
        case OpType::_cae:
            buf << "rcae";
            break;
        case OpType::_cbe:
            buf << "rcbe";
            break;
        case OpType::_ce:
            buf << "rce";
            break;
        case OpType::_cne:
            buf << "rcne";
            break;
        }


    if (type.getBaseType() == BaseType::_integer)
        switch (opType) {
        case OpType::_plus:
            buf << "iadd";
            break;
        case OpType::_minus:
            buf << "isub";
            break;
        case OpType::_div:
            buf << "idiv";
            break;
        case OpType::_rdiv:
            buf << "irdiv";
            break;
        case OpType::_mult:
            buf << "imull";
            break;
        case OpType::_mod:
            buf << "imod";
            break;
        case OpType::_ca:
            buf << "ica";
            break;
        case OpType::_cb:
            buf << "icb";
            break;
        case OpType::_cae:
            buf << "icae";
            break;
        case OpType::_cbe:
            buf << "icbe";
            break;
        case OpType::_ce:
            buf << "ice";
            break;
        case OpType::_cne:
            buf << "icne";
            break;
        case OpType::_and:
            buf << "iand";
            break;
        case OpType::_or:
            buf << "ior";
            break;
        case OpType::_xor:
            buf << "ixor";
            break;
        }


    if (type.getBaseType() == BaseType::_boolean)
        switch (opType) {
        case OpType::_and:
            buf << "iand";
            break;
        case OpType::_or:
            buf << "ior";
            break;
        case OpType::_xor:
            buf << "ixor";
            break;
        case OpType::_ce:
            buf << "ice";
            break;
        case OpType::_cne:
            buf << "icne";
            break;
        }

    if (type.getBaseType() == BaseType::_char)
        switch (opType) {
        case OpType::_ca:
            buf << "ica";
            break;
        case OpType::_cb:
            buf << "icb";
            break;
        case OpType::_cae:
            buf << "icae";
            break;
        case OpType::_cbe:
            buf << "icbe";
            break;
        case OpType::_ce:
            buf << "ice";
            break;
        case OpType::_cne:
            buf << "icne";
            break;
        case OpType::_plus:
            buf << "cadd";
            break;
        }

    if (type.getBaseType() == BaseType::_string)
        switch (opType) {
        case OpType::_ca:
            buf << "sca";
            break;
        case OpType::_cb:
            buf << "scb";
            break;
        case OpType::_cae:
            buf << "scae";
            break;
        case OpType::_cbe:
            buf << "scbe";
            break;
        case OpType::_ce:
            buf << "sce";
            break;
        case OpType::_cne:
            buf << "scne";
            break;
        case OpType::_plus:
            buf << "sadd";
            break;
        }

    buf << " $" << retAdress << " ";
    buf << " $" << leftAdress << " ";
    buf << " $" << rightAdress;
    return buf.str();
}

std::string BinarNode::getCode()
{
    code = "";

    BinarNode* rightNode = dynamic_cast<BinarNode*>(nodes[1]);
    rightNode->setDist(dist, isLocal);

    if (!first){
        rightNode->setDist(dist, isLocal);
        rightNode->setLeftAdress(leftAdress, isLeftLocal);
        return rightNode->getCode();
    }

    VirtualExprNode* right = dynamic_cast<VirtualExprNode*>(nodes[0]);

    if (!hasLeft && nodes[1]->getWay() == 0){
        right->setDist(dist, isLocal);
        return right->getCode();
    }

    Type rightType = right->getType();
    int rightAdress;


    std::stringstream buf;
    if (hasLeft){
        Type commonType = TypeConvertor::getCommonType(left, rightType);
        Type retType = commonType;
        if (opType == OpType::_ca || opType == OpType::_cb || opType == OpType::_cae ||
                opType == OpType::_cbe || opType == OpType::_ce || opType == OpType::_cne)
            retType = BaseType::_boolean;
        if (retType.getBaseType() == BaseType::_char)
            retType = BaseType::_string;

        buf.str("");
        buf << "push " << retType.getSize();
        emitCode(buf.str());
        int retAdress = symbolTable->getAdress();
        symbolTable->push(retType.getSize());


        buf.str("");
        buf << "push " << commonType.getSize() * 2;
        emitCode(buf.str());

        int leftCommon = symbolTable->getAdress();
        symbolTable->push(commonType.getSize());
        int rightCommon = symbolTable->getAdress();
        symbolTable->push(commonType.getSize());

        buf.str("");
        buf << "push " << rightType.getSize();
        emitCode(buf.str());

        rightAdress = symbolTable->getAdress();
        symbolTable->push(rightType.getSize());
        right->setDist(rightAdress, true);
        code = code + right->getCode();

        if (TypeConvertor::isEqual(commonType, left)){
            buf.str("");
            buf << "mov " << commonType.getSize() << " ";
            buf << "$" << leftCommon << " ";
            buf << "$" << leftAdress;
            emitCode(buf.str());
        } else
            if (commonType.getBaseType() == BaseType::_real){
                buf.str("");
                buf << "conv_r ";
                buf << "$" << leftCommon << " ";
                buf << "$" << leftAdress;
                emitCode(buf.str());
            } else{
                buf.str("");
                buf << "conv_s ";
                buf << "$" << leftCommon << " ";
                buf << "$" << leftAdress;
                emitCode(buf.str());
            }

        if (TypeConvertor::isEqual(commonType, rightType)){
            buf.str("");
            buf << "mov " << commonType.getSize() << " ";
            buf << "$" << rightCommon << " ";
            buf << "$" << rightAdress;
            emitCode(buf.str());
        } else
            if (commonType.getBaseType() == BaseType::_real){
                buf.str("");
                buf << "conv_r ";
                buf << "$" << rightCommon << " ";
                buf << "$" << rightAdress;
                emitCode(buf.str());
            } else{
                buf.str("");
                buf << "conv_s ";
                buf << "$" << rightCommon << " ";
                buf << "$" << rightAdress;
                emitCode(buf.str());
            }

        buf.str("");
        buf << "pop " << rightType.getSize();
        emitCode(buf.str());
        symbolTable->pop(rightType.getSize());

        emitCode(getOpCode(retAdress, leftCommon, rightCommon, commonType));

        buf.str("");
        buf << "pop " << commonType.getSize() * 2;
        emitCode(buf.str());
        symbolTable->pop(commonType.getSize() * 2);

        rightAdress = retAdress;
        rightType = retType;
    } else {
        buf.str("");
        buf << "push " << rightType.getSize();
        emitCode(buf.str());

        rightAdress = symbolTable->getAdress();
        symbolTable->push(rightType.getSize());
        right->setDist(rightAdress, true);
        code = code + right->getCode();
    }

    if (nodes[1]->getWay() != 0){
        rightNode->setDist(dist, isLocal);
        rightNode->setLeftAdress(rightAdress, true);
        code = code + rightNode->getCode();
    } else {
        buf.str("");
        buf << "mov ";
        buf << rightType.getSize();
        if (isLocal)
            buf << "$";
        else
            buf << "#";
        buf << dist << " ";
        buf << "$" << rightAdress;
        emitCode(buf.str());
    }

    buf.str("");
    buf << "pop " << rightType.getSize();
    emitCode(buf.str());
    symbolTable->pop(rightType.getSize());

    return code;
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

