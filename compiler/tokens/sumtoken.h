#ifndef SUMTOKEN_H
#define SUMTOKEN_H


#include <string>
#include <token.h>


class SumToken : public Token
{
public:
    enum SubType {plus, minus};

private:
    SubType subType;

public:

    SumToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}

    SubType getSubType();
};

#endif // SUMTOKEN_H
