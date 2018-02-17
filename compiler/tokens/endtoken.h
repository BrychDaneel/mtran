#ifndef ENDTOKEN_H
#define ENDTOKEN_H

#include <token.h>


class EndToken : public Token
{
public:
    EndToken();
    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}
};

#endif // ENDTOKEN_H
