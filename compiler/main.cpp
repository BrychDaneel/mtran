#include <lexicalanalizer.h>
#include <iostream>
#include <regex>

int main(int argc, char *argv[])
{
    LexicalAnalizer lex("/home/daneel/prog/mtran/temp/b.txt");

    do{
        std::cout << lex.pop()->getName() << " " << lex.front()->getLexem() << std::endl;
    } while (!lex.finished());
    std::cout << lex.pop()->getName() << " " << lex.front()->getLexem() << std::endl;
    return 0;
}
