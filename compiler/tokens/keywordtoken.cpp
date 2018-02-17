#include "keywordtoken.h"


KeyWordToken::KeyWordToken(const std::string lexem, const std::string regex, int id)
{
    this->lexem = lexem;
    this->regex = regex;
    this->name = regex;
    this->type = id;
}
