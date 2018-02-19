#include "lexicalanalizer.h"
#include <tokens/endtoken.h>
#include <tokens/spacetoken.h>
#include <tokens/commenttoken.h>
#include <tokens/semicolontoken.h>
#include <keywordsfactory.h>


Token* LexicalAnalizer::getUsefullToken()
{
    Token* token;
    do
        token = tokenFactory.getToken(strings);
    while (token->getType() == SpaceToken::TYPE || token->getType() == CommentToken::TYPE);
    return token;
}

bool LexicalAnalizer::fix()
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

        if (current->getType() == SemicolonToken::TYPE  && next->getType() == KeywordsFactory::getId("end") ){
            current = next;
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
    next = getUsefullToken();
}


Token *LexicalAnalizer::pop()
{
    Token* prev = current;

    current = next;
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
