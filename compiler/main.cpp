#include <syntaxanalizer.h>
#include <iostream>
#include <fstream>
#include <tokens/endtoken.h>
#include <tokens/idtoken.h>
#include <errorlog.h>
#include <iomanip>

void help(const char* prog){
    std::cerr << "Usage:" << std::endl;
    std::cerr << "\t" << std::string(prog) << " source dest [--lex] [--synt] [--sem] [--code]" << std::endl;
    exit(1);
}


int main(int argc, char* argv[])
{
    bool showLex = false;
    bool showSortedLex = false;
    bool showTree = false;
    bool showSem = false;
    bool showCode = false;
    if (argc < 3)
        help(argv[0]);

    for (int i=3; i<argc; i++)
        if (std::string(argv[i]) == "--lex")
            showLex = true;
        else if (std::string(argv[i]) == "--slex")
            showSortedLex = true;
        else if (std::string(argv[i]) == "--synt")
            showTree = true;
        else if (std::string(argv[i]) == "--sem")
            showSem = true;
        else if (std::string(argv[i]) == "--code")
            showCode = true;
        else
            help(argv[0]);

    if (showLex){
        std::cout << std::left;
        LexicalAnalizer lex(argv[1]);
        while (lex.front()->getType() != EndToken::TYPE){
            std::cout << std::setw(15) << lex.front()->getName();
            std::cout << std::setw(15) << lex.front()->getLexem();
            if (lex.front()->getType() == IdToken::TYPE)
                std::cout << std::setw(15)<< dynamic_cast<IdToken*>(lex.front())->getGID();
            std::cout << std::endl;
            lex.pop();
        }

        std::cout << "EOF" << std::endl;
    }

    if (showSortedLex){
        std::cout << std::left;
        LexicalAnalizer lex(argv[1]);
        std::vector<Token*> tokens;
        while (lex.front()->getType() != EndToken::TYPE){
            tokens.push_back(lex.front());
            lex.pop();
        }

        for (size_t i=0; i<tokens.size(); i++)
            for (size_t ii=i+1; ii<tokens.size(); ii++)
                if (tokens[i]->getName() > tokens[ii]->getName())
                    std::swap(tokens[i], tokens[ii]);

        std::string lastName = "";
        for (Token* token : tokens){
            if (lastName != "")
                if (lastName != token->getName())
                    std::cout << std::endl;
            lastName = token->getName();

            std::cout << "(";
            std::cout << std::setw(3) << token->getLine() << ", ";
            std::cout << std::setw(3) << token->getPos() << ") ";

            std::cout << std::setw(15) << token->getName();
            std::cout << std::setw(15) << token->getLexem();
            if (token->getType() == IdToken::TYPE)
                std::cout << std::setw(15)<< dynamic_cast<IdToken*>(token)->getGID();
            std::cout << std::endl;
        }

    }

    SyntaxAnalizer syn(argv[1]);
    Node* node = syn.parce();

    if (showTree)
        node->print();

    node->semantic();

    if (showSem)
        node->printTypes();

    std::string code = node->getCode();
    if (showCode)
        std::cout << code << std::endl;

    if (ErrorLog::hasError()){
        std::cerr << "COMPILATION FAILD" << std::endl;
        exit(1);
    }

    std::ofstream out(argv[2]);
    out << code;
    return 0;
}
