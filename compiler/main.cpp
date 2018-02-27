#include <syntaxanalizer.h>
#include <iostream>
#include <fstream>

int main(int /*argc*/, char* /*argv*/[])
{
    SyntaxAnalizer syn("/home/daneel/prog/mtran/temp/b.txt");

    Node* node = syn.parce();
    node->semantic();

    std::string code = node->getCode();
    std::cout << code << std::endl;

    std::ofstream out("/home/daneel/prog/mtran/temp/prog.bytecode");
    out << code;
    return 0;
}
