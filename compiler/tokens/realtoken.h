#ifndef REALTOKEN_H
#define REALTOKEN_H


#include <string>
#include <token.h>


class RealToken : public Token
{
    double value;
public:
    RealToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}

    double getValue();
};

#endif // REALTOKEN_H
