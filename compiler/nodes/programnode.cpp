#include "programnode.h"

#include <sstream>

ProgramNode::ProgramNode(SymbolTable *symbolTable, int way)
    : BaseNode(symbolTable, way)
{
}

std::string ProgramNode::getCode()
{
    std::stringstream buf;

    symbolTable->clearGlobVis();

    code = this->BaseNode::getCode();

    for (IdInfo* info : symbolTable->getThisVisable()){
        int pgid = info->getGId();
        buf.str("");
        buf << "pop " << symbolTable->getInfo(pgid)->getType().getSize();
        emitCode(buf.str());
    }
    return code;
}
