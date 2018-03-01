#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <pascalstring.h>
#include <map>

void help(const char * prog){
    std::cerr << "Usage:" << std::endl;
    std::cerr << "\t" << std::string(prog) << " program" << std::endl;
}

size_t parceAdress(std::vector<int64_t>& stack, std::string adress){
    std::stringstream s(adress);

    bool rel = false;
    char prefix;
    s >> prefix;
    if (prefix == '?'){
        rel = true;
        s >> prefix;
    }

    size_t adr;
    s >> adr;

    if (prefix=='$')
        adr += stack[0];

    if (adr >= stack.size()){
        std::cerr << "Invalid ardress" << std::endl;
        exit(1);
    }

    if (rel)
        adr = stack[adr];

    if (adr >= stack.size()){
        std::cerr << "Invalid ardress" << std::endl;
        exit(1);
    }

    return adr;
}


int main(int argc, char *argv[])
{
    if (argc != 2)
        help(argv[0]);

    const char* filename = argv[1];
    std::ifstream in(filename);
    std::vector<std::string> lines;
    std::map<int, int> labels;

    while (!in.eof()) {
        std::string s;
        std::getline(in, s);
        lines.push_back(s);
    }

    for (size_t i=0; i<lines.size(); i++){
        std::stringstream line(lines[i]);
        std::string cmd;
        line >> cmd;
        if (cmd == "label"){
            int lab;
            line >> lab;
            labels[lab] = i;
        }
    }

    size_t ip = 0;
    std::vector<int64_t> stack = {0};

    while (ip < lines.size()){
        if (lines[ip].size() == 0){
            ip++;
            continue;
        }
        std::stringstream line(lines[ip]);
        std::string cmd;
        line >> cmd;

        if (cmd == "write_i"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            std::cout << stack[adress];
        }

        if (cmd == "write_c"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            std::cout << (char)stack[adress];
        }

        if (cmd == "write_r"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            std::cout << *(double*)(&stack[adress]);
        }

        if (cmd == "write_s"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            PascalString pstr(stack, adress);
            std::cout << pstr.getStr();
        }

        if (cmd == "write_b"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            if (stack[adress])
                std::cout << "TRUE";
            else
                std::cout << "FALSE";
        }

        if (cmd == "read_i"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            std::cin >> stack[adress];
        }

        if (cmd == "read_c"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            char c;
            std::cin >> c;
            stack[adress] = c;
        }

        if (cmd == "read_r"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            double d;
            std::cin >> d;
            stack[adress] = *(int64_t*)&d;
        }

        if (cmd == "read_s"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);
            std::string str;
            std::getline(std::cin, str);
            PascalString pstr(str);
            pstr.writeStr(stack, adress);
        }


        if (cmd == "push"){
            int size;
            line >> size;
            for (int i=0; i<size; i++)
                stack.push_back(0);
        }

        if (cmd == "pop"){
            int size;
            line >> size;
            for (int i=0; i<size; i++)
                stack.pop_back();
        }

        if (cmd == "load_i"){
            std::string sAdress;
            line >> sAdress;
            int adress = parceAdress(stack, sAdress);

            int cnst;
            line >> cnst;

            stack[adress] = cnst;
        }

        if (cmd == "load_r"){
            std::string sAdress;
            line >> sAdress;
            size_t adress = parceAdress(stack, sAdress);

            double cnst;
            line >> cnst;

            stack[adress] = *(int64_t*)(&cnst);
        }

        if (cmd == "load_s"){
            std::string sAdress;
            line >> sAdress;
            size_t adress = parceAdress(stack, sAdress);

            std::string str;
            std::getline(line, str);
            str.erase(str.begin());

            PascalString pstr(str);
            pstr.writeStr(stack, adress);
        }

        if (cmd == "mov"){
            int size;
            line >> size;

            std::string sAdress;
            line >> sAdress;
            size_t distAdress = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t sourceAdress = parceAdress(stack, sAdress);

            for (int i=0; i<size; i++)
                stack[distAdress + i] = stack[sourceAdress + i];
        }

        if ( cmd == "radd" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            double res = *(double*)&stack[left] + *(double*)&stack[right];
            stack[dist] = *(int64_t*)&res;
        }

        if ( cmd == "rsub" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            double res = *(double*)&stack[left] - *(double*)&stack[right];
            stack[dist] = *(int64_t*)&res;
        }

        if ( cmd == "rdiv" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            double res = *(double*)&stack[left] / *(double*)&stack[right];
            stack[dist] = *(int64_t*)&res;
        }

        if ( cmd == "rmull" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            double res = *(double*)&stack[left] * *(double*)&stack[right];
            stack[dist] = *(int64_t*)&res;
        }

        if ( cmd == "rca" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = *(double*)&stack[left] > *(double*)&stack[right];
        }

        if ( cmd == "rcb" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = *(double*)&stack[left] < *(double*)&stack[right];
        }

        if ( cmd == "rcae" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = *(double*)&stack[left] >= *(double*)&stack[right];
        }

        if ( cmd == "rcbe" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = *(double*)&stack[left] <= *(double*)&stack[right];
        }

        if ( cmd == "rce" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = *(double*)&stack[left] == *(double*)&stack[right];
        }

        if ( cmd == "rcne" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = *(double*)&stack[left] != *(double*)&stack[right];
        }

        if ( cmd == "iadd" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] + stack[right];
        }

        if ( cmd == "isub" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] - stack[right];
        }

        if ( cmd == "idiv" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] / stack[right];
        }

        if ( cmd == "irdiv" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            double res = stack[left] / (double) stack[right];
            stack[dist] = *(int64_t*)(&res);
        }


        if ( cmd == "imull" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] * stack[right];
        }

        if ( cmd == "imod" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] % stack[right];
        }

        if ( cmd == "ica" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] > stack[right];
        }

        if ( cmd == "icb" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] < stack[right];
        }

        if ( cmd == "icae" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] >= stack[right];
        }

        if ( cmd == "icbe" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] <= stack[right];
        }

        if ( cmd == "ice" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] == stack[right];
        }

        if ( cmd == "icne" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] != stack[right];
        }

        if ( cmd == "iand" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] & stack[right];
        }

        if ( cmd == "ior" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] | stack[right];
        }

        if ( cmd == "ixor" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            stack[dist] = stack[left] ^ stack[right];
        }

        if ( cmd == "cadd" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            std::string lstr;
            lstr.push_back( (char)stack[left] );
            std::string rstr;
            lstr.push_back( (char)stack[right] );
            PascalString res(lstr + rstr);
            res.writeStr(stack, dist);
        }

        if ( cmd == "sca" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            PascalString lstr(stack, left);
            PascalString rstr(stack, right);
            stack[dist] = lstr.getStr() > rstr.getStr();
        }

        if ( cmd == "scb" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            PascalString lstr(stack, left);
            PascalString rstr(stack, right);
            stack[dist] = lstr.getStr() < rstr.getStr();
        }

        if ( cmd == "scae" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            PascalString lstr(stack, left);
            PascalString rstr(stack, right);
            stack[dist] = lstr.getStr() >= rstr.getStr();
        }

        if ( cmd == "scbe" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            PascalString lstr(stack, left);
            PascalString rstr(stack, right);
            stack[dist] = lstr.getStr() <= rstr.getStr();
        }

        if ( cmd == "sce" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            PascalString lstr(stack, left);
            PascalString rstr(stack, right);
            stack[dist] = lstr.getStr() == rstr.getStr();
        }

        if ( cmd == "scne" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            PascalString lstr(stack, left);
            PascalString rstr(stack, right);
            stack[dist] = lstr.getStr() != rstr.getStr();
        }

        if ( cmd == "sadd" )
        {
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t right = parceAdress(stack, sAdress);
            PascalString lstr(stack, left);
            PascalString rstr(stack, right);
            PascalString res(lstr.getStr() + rstr.getStr());
            res.writeStr(stack, dist);
        }

        if (cmd == "iminus"){
            std::string sAdress;
            line >> sAdress;
            size_t var = parceAdress(stack, sAdress);
            stack[var] = -stack[var];
        }

        if (cmd == "inot"){
            std::string sAdress;
            line >> sAdress;
            size_t var = parceAdress(stack, sAdress);
            stack[var] = ~stack[var];
        }

        if (cmd == "rminus"){
            std::string sAdress;
            line >> sAdress;
            size_t var = parceAdress(stack, sAdress);
            double res = -*(double*)&stack[var];
            stack[var] = *(int64_t*)&res;
        }

        if (cmd == "bnot"){
            std::string sAdress;
            line >> sAdress;
            size_t var = parceAdress(stack, sAdress);
            stack[var] = stack[var] ^ 1;
        }

        if ( cmd == "conv_r" ){
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            double res = stack[left];
            stack[dist] = *(int64_t*)&res;
        }

        if ( cmd == "conv_s" ){
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t left = parceAdress(stack, sAdress);
            std::string str;
            str.push_back((char) stack[left]);
            PascalString pstr(str);
            pstr.writeStr(stack, dist);
        }

        if ( cmd == "jt" ){
            int lab;
            line >> lab;
            std::string sAdress;
            line >> sAdress;
            size_t expr = parceAdress(stack, sAdress);
            if (stack[expr])
                ip = labels[lab];
        }

        if ( cmd == "jf" ){
            int lab;
            line >> lab;
            std::string sAdress;
            line >> sAdress;
            size_t expr = parceAdress(stack, sAdress);
            if (!stack[expr])
                ip = labels[lab];
        }

        if ( cmd == "jmp" ){
            int lab;
            line >> lab;
            ip = labels[lab];
        }


        if ( cmd == "call" ){
            int size;
            line >> size;
            int lab;
            line >> lab;
            stack.push_back(stack[0]);
            stack.push_back(ip);
            stack[0] = stack.size() - 2 - size;
            ip = labels[lab];
        }

        if ( cmd == "ret" ){
            ip = stack[stack.size()-1];
            stack.pop_back();
            stack[0] = stack[stack.size()-1];
            stack.pop_back();
        }


        if ( cmd == "mov_from_s" ){
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t strAress = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t charAress = parceAdress(stack, sAdress);
            PascalString pstr(stack, strAress);
            stack[dist] = pstr.getStr()[charAress];
        }

        if ( cmd == "mov_to_s" ){
            std::string sAdress;
            line >> sAdress;
            size_t dist = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t valAress = parceAdress(stack, sAdress);
            line >> sAdress;
            size_t indAress = parceAdress(stack, sAdress);
            PascalString pstr(stack, dist);
            std::string res = pstr.getStr();
            res[indAress] = stack[valAress];
            PascalString pres(res);
            pres.writeStr(stack, dist
                          );
        }


        ip++;
    }


    if (stack.size() != 1)
        std::cerr << std::endl << "Stack leek: " << stack.size() << std::endl;
}
