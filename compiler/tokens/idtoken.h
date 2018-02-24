#ifndef BEGINTOKEN_H
#define BEGINTOKEN_H

#include <string>
#include <token.h>

class IdToken : public Token
{
    int gid = -1;
    std::string lowerLexem;

public:
    IdToken(const std::string lexem);

    static const int TYPE;
    static const std::string REGEX;
    static const std::string NAME;

    static Token* create(const std::string lexem);

    int getType() {return TYPE;}
    const std::string getRegex() {return REGEX;}
    const std::string getName() {return NAME;}

    void setGID(int gid);
    int getGID();

    const std::string &getLowerLexem();
};

#endif // BEGINTOKEN_H
