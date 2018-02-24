#ifndef INVALIDTOKEN_H
#define INVALIDTOKEN_H


#include <string>
#include <token.h>

class InvalidToken : public Token
{
public:
    InvalidToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}
};

#endif // INVALIDTOKEN_H
