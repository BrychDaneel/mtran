#ifndef ERRORLOG_H
#define ERRORLOG_H

#include <string>

class ErrorLog
{
    static int lexicaCount;
    static int syntaxCount;
public:
    static void LexicalError(std::string mes);
    static void SyntaxError(std::string mes);
    static std::string getTokenStr(int type);
    static bool hasError();
};

#endif // ERRORLOG_H
