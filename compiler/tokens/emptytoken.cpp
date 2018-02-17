#include "emptytoken.h"


const int EmptyToken::TYPE = 0;
const std::string EmptyToken::REGEX = "" ;
const std::string EmptyToken::NAME = "null";


EmptyToken::EmptyToken()
{
    this->lexem = "";
}
