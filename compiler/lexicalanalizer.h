#ifndef LEXICALANALIZER_H
#define LEXICALANALIZER_H


#include <token.h>
#include <codesource.h>
#include <tokenfactory.h>
#include <symboltable.h>

class LexicalAnalizer
{
    CodeSource src;
    TokenFactory tokenFactory;
    std::string strings;
    Token* current = nullptr;
    Token* next = nullptr;
    Token* lastAnyToken = nullptr;

    Token *getAnyToken();
    Token *getUsefullToken();
    void fix();

    SymbolTable symbolTable;

    int line = 1;
    int position = 1;
    int nextLine = 1;
    int nextPosition = 1;

public:
    LexicalAnalizer(const std::string filename);
    Token* pop();
    Token* front();
    bool finished();
    SymbolTable* getSymbolTable();
    int getLine();
    int getPosition();
};

#endif // LEXICALANALIZER_H
