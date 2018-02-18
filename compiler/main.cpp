#include <syntaxanalizer.h>
#include <iostream>

int main(int argc, char *argv[])
{
    SyntaxAnalizer syn("/home/daneel/prog/mtran/temp/b.txt");

    Node* node = syn.parce();
    node->print();

    return 0;
}
