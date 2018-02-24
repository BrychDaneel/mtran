#include "emptyrule.h"

#include <tokens/emptytoken.h>

EmptyRule* EmptyRule::instance;


void EmptyRule::setup()
{
    first.insert(EmptyToken::TYPE);
}

EmptyRule *EmptyRule::getInstance()
{
    if (instance == nullptr){
        instance = new EmptyRule;
        instance->setup();
    }
    return instance;
}

Node *EmptyRule::parce(LexicalAnalizer* /*lex*/)
{
    return new EmptyNode();
}
