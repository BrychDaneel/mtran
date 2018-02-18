#include "endtoken.h"


const int EndToken::TYPE = -1;
const std::string EndToken::REGEX = "" ;
const std::string EndToken::NAME = "$";


EndToken::EndToken()
{
    this->lexem = EndToken::NAME;
}
