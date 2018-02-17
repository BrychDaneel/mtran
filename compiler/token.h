#ifndef TOKEN_H
#define TOKEN_H

#include <string>


class Token
{
protected:
    std::string lexem;
public:
    virtual ~Token(){}

    virtual const std::string getLexem();
    virtual const std::string getRegex() = 0;
    virtual int getType() = 0;
    virtual const std::string getName() = 0;
};

#endif // TOKEN_H
