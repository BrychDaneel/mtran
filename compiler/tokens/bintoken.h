#ifndef BINTOKEN_H
#define BINTOKEN_H


#include <string>
#include <token.h>


class BinToken : public Token
{
public:
    BinToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}
};

#endif // BINTOKEN_H
