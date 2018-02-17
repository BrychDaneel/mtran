#include "spacetoken.h"


const int SpaceToken::TYPE = 1;
const std::string SpaceToken::REGEX = "\\s+";
const std::string SpaceToken::NAME = "spaces";


SpaceToken::SpaceToken(const std::string lexem)
{
    this->lexem = "<somespaces>";
}

Token *SpaceToken::create(const std::string lexem)
{
    return new SpaceToken(lexem);
}
