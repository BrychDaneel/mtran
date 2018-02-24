#include "idtoken.h"

#include <keywordsfactory.h>
#include <algorithm>

const int IdToken::TYPE = 101;
const std::string IdToken::REGEX = "(_|[a-zA-Z])\\w*" ;
const std::string IdToken::NAME = "id";


IdToken::IdToken(const std::string lexem)
{
    this->lexem = lexem;
    lowerLexem = lexem;
    std::transform(lowerLexem.begin(), lowerLexem.end(), lowerLexem.begin(), tolower);
}

Token *IdToken::create(const std::string lexem)
{
    if (KeywordsFactory::isKeyword(lexem))
        return KeywordsFactory::createToken(lexem);

    return new IdToken(lexem);
}

void IdToken::setGID(int gid)
{
    this->gid = gid;
}

int IdToken::getGID()
{
    return gid;
}

const std::string& IdToken::getLowerLexem()
{
    return lowerLexem;
}


