#ifndef TOKENFACTORY_H
#define TOKENFACTORY_H


#include <string>
#include <token.h>
#include <vector>
#include <regex>


class TokenFactory
{
    std::vector<std::regex> tokenRegexs;
    std::vector<Token* (*) (std::string)> tokenEmitors;
public:
    TokenFactory();
    void reg(const std::string regex, Token* (*create) (const std::string));
    Token* getToken(std::string& text);
};

#endif // TOKENFACTORY_H
