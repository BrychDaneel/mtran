#ifndef DOTDOTTOKEN_H
#define DOTDOTTOKEN_H


#include <string>
#include <token.h>


class DotDotToken : public Token
{
public:
    DotDotToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}
};

#endif // DOTDOTTOKEN_H
