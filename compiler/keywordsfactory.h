#ifndef KEYWORDSFACTORY_H
#define KEYWORDSFACTORY_H

#include <string>
#include <vector>
#include <token.h>

class KeywordsFactory
{

static std::vector<std::string> keywords;
static std::vector<int> keywordsId;

public:

    static bool isKeyword(std::string id);
    static int getId(std::string keyword);

    static Token* createToken(std::string keyword);
};

#endif // KEYWORDSFACTORY_H
