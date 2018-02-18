#ifndef FACTTOKEN_H
#define FACTTOKEN_H


#include <string>
#include <token.h>


class FactToken : public Token
{
public:
    enum SubType{div, mult};
private:
    SubType subType;
public:
    FactToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}
};

#endif // FACTTOKEN_H
