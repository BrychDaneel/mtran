#ifndef ADRESSTOKEN_H
#define ADRESSTOKEN_H


#include <string>
#include <token.h>


class AdressToken : public Token
{
public:
    AdressToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}
};

#endif // ADRESSTOKEN_H
