#ifndef TOKEN_H
#define TOKEN_H

#include <string>


class Token
{
protected:
    std::string lexem;
    int line = 0;
    int pos = 0;
public:
    virtual ~Token(){}

    virtual const std::string getLexem();
    virtual const std::string getRegex() = 0;
    virtual int getType() = 0;
    virtual const std::string getName() = 0;

    void setLine(int line);
    void setPos(int pos);

    int getLine();
    int getPos();
};

#endif // TOKEN_H
