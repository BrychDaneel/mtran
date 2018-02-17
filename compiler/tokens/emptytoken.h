#ifndef EMPTYTOKEN_H
#define EMPTYTOKEN_H


#include <token.h>


class EmptyToken : public Token
{
public:
    EmptyToken();
    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}
};

#endif // EMPTYTOKEN_H
