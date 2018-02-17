#include "keywordsfactory.h"

#include <iostream>
#include <algorithm>
#include <tokens/keywordtoken.h>

std::vector<std::string> KeywordsFactory::keywords = {
    "and", "array", "asm", "begin", "case", "const", "div", "do",
    "else", "end", "for", "function", "if",
    "mod", "not",
    "of", "or", "procedure", "program", "repeat", "string",
    "then", "to", "until", "var", "while", "xor"};
std::vector<int> KeywordsFactory::keywordsId =
    {501, 502, 503, 504, 505, 506, 507, 508,
    509, 510, 511, 512, 513,
    514, 515,
    516, 517, 518, 519, 520, 521,
    522, 523, 524, 525, 526, 527};

bool KeywordsFactory::isKeyword(std::string id)
{
    std::transform(id.begin(), id.end(), id.begin(), tolower);

    return std::find(keywords.begin(), keywords.end(), id) != keywords.end();
}

int KeywordsFactory::getId(std::string keyword)
{
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), tolower);
    for (size_t i=0; i<keywords.size(); i++)
        if (keywords[i] == keyword)
            return keywordsId[i];

    std::cerr << "Can't find keywords" << std::endl;
    exit(1);
}

Token *KeywordsFactory::createToken(std::string keyword)
{
    std::string lexem = keyword;
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), tolower);
    return new KeyWordToken(lexem, keyword, getId(keyword));
}
