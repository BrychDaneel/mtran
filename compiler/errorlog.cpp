#include "errorlog.h"

#include <iostream>
#include <keywordsfactory.h>


int ErrorLog::lexicaCount = 0;
int ErrorLog::syntaxCount = 0;


void ErrorLog::LexicalError(std::string mes)
{
    lexicaCount ++;
    std::cerr << mes << std::endl;
    if (lexicaCount >= 4)
        exit(1);
}

void ErrorLog::SyntaxError(std::string mes)
{
    syntaxCount ++;
    std::cerr << mes << std::endl;
    if (syntaxCount >= 4)
        exit(1);
}

std::string ErrorLog::getTokenStr(int type)
{
    if (KeywordsFactory::isKeyword(type))
        return KeywordsFactory::getStr(type);

    switch (type) {
    case -1:
        return "EOF";
    case 0:
        return "NULL";
    case 1:
        return "SPACE";
    case 2:
        return "COMMENT";
    case 3:
        return "INVALID";
    case 101:
        return "ID";
    case 301:
        return "@";
    case 302:
        return ":=";
    case 303:
        return "+ or -";
    case 304:
        return ":";
    case 305:
        return ",";
    case 306:
        return "..";
    case 307:
        return ".";
    case 308:
        return "> or < or >= or <= or = or <>";
    case 309:
        return "*";
    case 310:
        return "{";
    case 311:
        return "(";
    case 312:
        return "[";
    case 313:
        return "}";
    case 314:
        return ")";
    case 315:
        return "]";
    case 316:
        return ";";
    case 317:
        return "+ or -";
    case 318:
        return "^";

    case 400:
        return "INTEGER";
    case 401:
        return "REAL";
    case 402:
        return "STRING";
    case 403:
        return "CHAR";
    }

    std::cerr << "Invalid type id" << std::endl;
    exit(1);
}

bool ErrorLog::hasError()
{
    return lexicaCount != 0 || syntaxCount != 0;
}
