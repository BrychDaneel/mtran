#include "tokenfactory.h"
#include <tokens/endtoken.h>
#include <iostream>


#include <tokens/integertoken.h>
#include <tokens/realtoken.h>
#include <tokens/stringtoken.h>
#include <tokens/chartoken.h>

#include <tokens/adresstoken.h>
#include <tokens/assigntoken.h>
#include <tokens/bintoken.h>
#include <tokens/colontoken.h>
#include <tokens/comatoken.h>
#include <tokens/commenttoken.h>
#include <tokens/dotdottoken.h>
#include <tokens/dottoken.h>
#include <tokens/emptytoken.h>
#include <tokens/endtoken.h>
#include <tokens/eqtoken.h>
#include <tokens/facttoken.h>
#include <tokens/idtoken.h>
#include <tokens/leftbracetoken.h>
#include <tokens/leftbrackettoken.h>
#include <tokens/leftsquartoken.h>
#include <tokens/rightbracetoken.h>
#include <tokens/rightbrackettoken.h>
#include <tokens/rightsquartoken.h>
#include <tokens/semicolontoken.h>
#include <tokens/spacetoken.h>
#include <tokens/sumtoken.h>
#include <tokens/valuetoken.h>
#include <tokens/ynartoken.h>
#include <tokens/invalidtoken.h>


void TokenFactory::reg(const std::string regex, Token* (*create)(const std::string))
{
    tokenRegexs.push_back(std::regex("^(" + regex + ")"));
    tokenEmitors.push_back(create);
}

Token* TokenFactory::getToken(std::string& text)
{
    if (text.size() == 0)
        return new EndToken;

    for (size_t i=0; i<tokenRegexs.size(); i++){
        std::smatch match;
        if (std::regex_search(text, match, tokenRegexs[i])){
            std::string result = match.str();
            text.erase(text.begin(), text.begin() + result.size());
            return tokenEmitors[i](result);
        }
    }

    std::cerr << "ERROR: Lexical error" << std::endl;
    std::cerr << text.substr(0, 10) << std::endl;
    exit(1);
}


TokenFactory::TokenFactory()
{
    reg(SpaceToken::REGEX, &SpaceToken::create);
    reg(CommentToken::REGEX, &CommentToken::create);

    reg(IdToken::REGEX, &IdToken::create);

    reg(RealToken::REGEX, &RealToken::create);
    reg(IntegerToken::REGEX, &IntegerToken::create);
    reg(CharToken::REGEX, &CharToken::create);
    reg(StringToken::REGEX, &StringToken::create);

    reg(AdressToken::REGEX, &AdressToken::create);
    reg(AssignToken::REGEX, &AssignToken::create);
    //reg(BinToken::REGEX, &BinToken::create);
    reg(ColonToken::REGEX, &ColonToken::create);
    reg(ComaToken::REGEX, &ComaToken::create);
    reg(DotDotToken::REGEX, &DotDotToken::create);
    reg(DotToken::REGEX, &DotToken::create);
    reg(EQToken::REGEX, &EQToken::create);
    reg(FactToken::REGEX, &FactToken::create);
    reg(SemicolonToken::REGEX, &SemicolonToken::create);
    reg(SumToken::REGEX, &SumToken::create);
    reg(ValueToken::REGEX, &ValueToken::create);


    reg(LeftBraceToken::REGEX, &LeftBraceToken::create);
    reg(RightBraceToken::REGEX, &RightBraceToken::create);

    reg(LeftBracketToken::REGEX, &LeftBracketToken::create);
    reg(RightBracketToken::REGEX, &RightBracketToken::create);

    reg(LeftSquarToken::REGEX, &LeftSquarToken::create);
    reg(RightSquarToken::REGEX, &RightSquarToken::create);

    reg(InvalidToken::REGEX, &InvalidToken::create);

}
