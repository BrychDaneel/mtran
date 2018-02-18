#ifndef SYNTAXANALIZER_H
#define SYNTAXANALIZER_H

#include <string>
#include <lexicalanalizer.h>
#include <rules/rootrule.h>

class SyntaxAnalizer
{
    LexicalAnalizer lex;
    RootRule* rule;
public:
    SyntaxAnalizer(std::string filename);
    Node* parce();
};

#endif // SYNTAXANALIZER_H
