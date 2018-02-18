#include "emptytoken.h"


const int EmptyToken::TYPE = 0;
const std::string EmptyToken::REGEX = "" ;
const std::string EmptyToken::NAME = "[NULL]";


EmptyToken::EmptyToken()
{
    this->lexem = EmptyToken::NAME;
}
