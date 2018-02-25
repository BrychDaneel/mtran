#include "lexicalanalizer.h"
#include <tokens/endtoken.h>
#include <tokens/spacetoken.h>
#include <tokens/commenttoken.h>
#include <tokens/semicolontoken.h>
#include <keywordsfactory.h>

#include <tokens/idtoken.h>
#include <tokens/invalidtoken.h>

#include <iostream>

Token *LexicalAnalizer::getAnyToken()
{
    if (lastAnyToken != nullptr)
        for (char c : lastAnyToken->getLexem())
            if (c == '\n'){
                nextLine++;
                nextPosition = 1;
            } else
                if (c != '\r')
                    nextPosition++;
    lastAnyToken = tokenFactory.getToken(strings);
    lastAnyToken->setLine(nextLine);
    lastAnyToken->setPos(nextPosition);
    return lastAnyToken;
}

Token* LexicalAnalizer::getUsefullToken()
{
    Token* token;
    do{
        token = getAnyToken();
        if (token->getType() == InvalidToken::TYPE){
            std::cerr << "LEXICAL ERROR ("<< nextLine << "," << nextPosition << ") Unknown token: " << token->getLexem() << std::endl;
            exit(1);
        }
    }while (token->getType() == SpaceToken::TYPE || token->getType() == CommentToken::TYPE || token->getType()== InvalidToken::TYPE);

    if (token->getType() ==  IdToken::TYPE){
        IdToken* itok = dynamic_cast<IdToken*>(token);
        itok->setGID(symbolTable.getGID(token->getLexem()));
    }

    return token;
}

void LexicalAnalizer::fix()
{
    bool norm = false;
    while (!norm){
        norm = true;

        if (current->getType() == SemicolonToken::TYPE && next->getType() == SemicolonToken::TYPE ){
            next = getUsefullToken();
            norm = false;
        }

        if (current->getType() == KeywordsFactory::getId("begin") && next->getType() == SemicolonToken::TYPE ){
            next = getUsefullToken();
            norm = false;
        }

        if (current->getType() == SemicolonToken::TYPE  &&
                (next->getType() == KeywordsFactory::getId("end") || next->getType() == KeywordsFactory::getId("until"))){
            current = next;
            position = nextPosition;
            line = nextLine;

            next = getUsefullToken();
            norm = false;
        }

    }
}



LexicalAnalizer::LexicalAnalizer(const std::string filename)
    :src(filename)
{
    strings = src.full();
    current = getUsefullToken();
    position = nextPosition;
    line = nextLine;
    next = getUsefullToken();
    fix();
}


Token *LexicalAnalizer::pop()
{
    Token* prev = current;

    current = next;
    position = nextPosition;
    line = nextLine;

    next = getUsefullToken();

    fix();

    return prev;
}



Token *LexicalAnalizer::front()
{
    return current;
}

bool LexicalAnalizer::finished()
{
    return current->getType() == EndToken::TYPE;
}

SymbolTable *LexicalAnalizer::getSymbolTable()
{
    return &symbolTable;
}

int LexicalAnalizer::getLine()
{
    return line;
}

int LexicalAnalizer::getPosition()
{
    return position;
}
