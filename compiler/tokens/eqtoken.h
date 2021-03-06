#ifndef EQTOKEN_H
#define EQTOKEN_H


#include <string>
#include <token.h>


class EQToken : public Token
{
public:
    enum SubType{ce, cne, ca, cb, cbe, cae};
private:
    SubType subType;
public:
    EQToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}

    SubType getSubType();
};

#endif // NETOKEN_H
