#ifndef INTEGERTOKEN_H
#define INTEGERTOKEN_H


#include <string>
#include <token.h>


class IntegerToken : public Token
{
    int value;

public:
    IntegerToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}

    int getValue();
};

#endif // INTEGERTOKEN_H
