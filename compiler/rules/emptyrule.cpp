#include "emptyrule.h"

#include <tokens/emptytoken.h>

EmptyRule* EmptyRule::instance;


EmptyRule::EmptyRule()
{
    first.insert(EmptyToken::TYPE);
}

EmptyRule *EmptyRule::getInstance()
{
    if (instance == nullptr){
        instance = new EmptyRule;
    }
    return instance;
}

Node *EmptyRule::parce(LexicalAnalizer *lex)
{
    return new EmptyNode();
}
