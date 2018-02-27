#include "pascalstring.h"

#include <sstream>

PascalString::PascalString(){

}

PascalString::PascalString(std::vector<int64_t> &stack, int adress)
{
    readStr(stack, adress);
}

PascalString::PascalString(std::string str)
{
    this->str = str;
}

std::string PascalString::getStr()
{
    return str;
}

void PascalString::readStr(std::vector<int64_t> &stack, int adress)
{
    std::stringstream buf;
    for (int i=0; i<32; i++)
        buf.write((char*)&stack[adress + i], sizeof(int64_t));
    uint8_t size;
    buf.read((char*)&size, sizeof(uint8_t));
    str = "";
    for (int i=0; i<size; i++){
        char c;
        buf.read(&c, sizeof(char));
        str = str + c;
    }
}

void PascalString::writeStr(std::vector<int64_t> &stack, int adress)
{
    std::stringstream buf;
    char size = str.size();
    buf.write(&size, sizeof(char));
    for (char c : str)
        buf << c;

    for (int i=str.size()+1; i<256; i++)
        buf << '\0';

    for (int i=0; i<32; i++){
        int64_t a;
        buf.read((char*)&a, sizeof(int64_t));
        stack[adress + i] = a;
    }
}

void PascalString::pushBack(char c)
{
    str = str + c;
}

void PascalString::pushFront(char c)
{
    str = c + str;
}

