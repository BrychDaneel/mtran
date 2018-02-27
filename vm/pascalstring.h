#ifndef PASCALSTRING_H
#define PASCALSTRING_H

#include <string>
#include <vector>

class PascalString
{
    std::string str;
public:
    PascalString();
    PascalString(std::string str);
    PascalString(std::vector<int64_t>& stack, int adress);
    std::string getStr();
    void readStr(std::vector<int64_t>& stack, int adress);
    void writeStr(std::vector<int64_t>& stack, int adress);
    void pushBack(char c);
    void pushFront(char c);

};

#endif // PASCALSTRING_H
