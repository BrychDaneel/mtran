#include "idtoken.h"

#include <keywordsfactory.h>

const int IdToken::TYPE = 101;
const std::string IdToken::REGEX = "(_|[a-zA-Z])\\w*" ;
const std::string IdToken::NAME = "id";


IdToken::IdToken(const std::string lexem)
{
    this->lexem = lexem;
}

Token *IdToken::create(const std::string lexem)
{
    if (KeywordsFactory::isKeyword(lexem))
        return KeywordsFactory::createToken(lexem);

    return new IdToken(lexem);
}
