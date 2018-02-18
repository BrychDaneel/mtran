#ifndef STRINGTOKEN_H
#define STRINGTOKEN_H


#include <string>
#include <token.h>


class StringToken : public Token
{
    std::string value;

public:
    StringToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}

    std::string getValue();
};

#endif // STRINGTOKEN_H
