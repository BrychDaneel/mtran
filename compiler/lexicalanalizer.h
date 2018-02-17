#ifndef LEXICALANALIZER_H
#define LEXICALANALIZER_H


#include <token.h>
#include <codesource.h>
#include <tokenfactory.h>


class LexicalAnalizer
{
    CodeSource src;
    TokenFactory tokenFactory;
    std::string strings;
    Token* current;

public:
    LexicalAnalizer(const std::string filename);
    Token* pop();
    Token* front();
    bool finished();
};

#endif // LEXICALANALIZER_H
