#include "lexicalanalizer.h"
#include <tokens/endtoken.h>
#include <tokens/spacetoken.h>
#include <tokens/commenttoken.h>


LexicalAnalizer::LexicalAnalizer(const std::string filename)
    :src(filename)
{
    strings = src.full();
    do
        current = tokenFactory.getToken(strings);
    while (current->getType() == SpaceToken::TYPE || current->getType() == CommentToken::TYPE);

}


Token *LexicalAnalizer::pop()
{
    Token* prev = current;
    do
        current = tokenFactory.getToken(strings);
    while (current->getType() == SpaceToken::TYPE || current->getType() == CommentToken::TYPE);
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
