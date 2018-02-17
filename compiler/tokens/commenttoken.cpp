#include "commenttoken.h"


const int CommentToken::TYPE = 2;
const std::string CommentToken::REGEX = "(\\/\\*(.|[\\n\\r])*?\\*\\/)|(\\/\\/.*)" ;
const std::string CommentToken::NAME = "comment";


CommentToken::CommentToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *CommentToken::create(const std::string lexem)
{
    return new CommentToken(lexem);
}
