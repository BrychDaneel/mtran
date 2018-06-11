#ifndef KEYWORDTOKEN_H
#define KEYWORDTOKEN_H

#include <string>
#include <token.h>

class KeyWordToken : public Token
{

private:
    int type;
    std::string regex;
    std::string name;

public:
    KeyWordToken(const std::string lexem, const std::string regex, int id);

    int getType() {return type;}
    const std::string getRegex() {return regex;}
    const std::string getName() {return "keyword";}
};

#endif // KEYWORDTOKEN_H
