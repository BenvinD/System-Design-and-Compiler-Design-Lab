#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <regex>
#include <map>
#include <algorithm>
int main()
{
char inp[1000];
std::ifstream data; data.open("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/input.txt");
freopen("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/output.txt","w", stdout);
std::cout<<"Name:   Benvin"<<std::endl<<"Reg No: URK19CS1060"<<std::endl<<std::endl;
bool flag = true;
std::ifstream optab; optab.open("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/optab.txt");
std::fstream symtab; symtab.open("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/symtab.txt");
optab.seekg(0, std::ios::end);
int file_size = optab.tellg();
optab.close();
std::vector<std::string> sym;
std::vector<std::string> symfin;
std::vector<std::string> cur;
std::vector<std::string> op;
optab.open("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/optab.txt");
std::string wo;
    while (optab >> wo)
        op.push_back(wo);
if(data.is_open()){ 
    while(data.good()){
        data.getline(inp,1000);
        std::string str(inp);
        std::istringstream iss(str);
        std::string word;
        int co = 0;
        while(iss >> word)
        {
            co++;
            sym.push_back(word.c_str());
            cur.push_back(word.c_str());
        }
        if(co==2)
            {
                sym.pop_back();
                sym.pop_back();
            }
        if(co==1)
            sym.pop_back();
    }
}
int add = stoi(sym[2]);
for(int j = 0;j<sym.size(); j++)
{
    if(sym[j+1]=="START")
    {
        //symtab<<sym[j+1]<<" "<<add<<std::endl;
        add+=3;
    }
    else
    {
        if(sym[j+1]=="RESW")
        {
        add += stoi(sym[j+2])*3;
        symtab<<sym[j]<<" "<<add<<std::endl;
        symfin.push_back(sym[j]);
        symfin.push_back(std::to_string(add));
        j+=2;
        }
        if(sym[j+1]=="RESB")
        {
        add += stoi(sym[j+2]);
        symtab<<sym[j]<<" "<<add<<std::endl;
        symfin.push_back(sym[j]);
        symfin.push_back(std::to_string(add));
        j+=2;
        }
    }
}
for(int i=0;i<cur.size();i++)
{
    if(i==0)
    {
        std::cout<<"H"<<"^"<<cur[i]<<"^"<<cur[i+2]<<"^"<<std::setfill ('0') << std::setw(2) << std::hex << file_size-1<<std::endl;
        std::cout<<"T^"<<std::setfill ('0') << std::setw(6)<<sym[2]<<"^"<<std::setfill ('0') << std::setw(2)<<std::hex << op[1].length()+op[2].length()+1;
    }
    if(i>2)
    {
        for(int j=0;j<op.size();j++)
        {
            if(op[j]==cur[i])
            {
                std::cout<<"^"<<op[j+1];
            }
        }
        for(int j=0;j<symfin.size();j++)
        {
            if(op[j]==cur[i])
            {
                std::cout<<symfin[j+1];
            }
        }
    }
    if(cur[i]=="END")
    {
       std::cout<<std::endl<<"E^"<<std::setfill ('0') << std::setw(6)<<sym[2]; 
    }
}
}
/*
optab:
STA 23
LDA 00

input:
COPY START 1000
LDA ALPHA
STA BETA
ALPHA RESW 1
BETA RESW 1
END

Symtab:
ALPHA 1006
BETA 1009

output:
Name:   Benvin
Reg No: URK19CS1060

H^COPY^1000^0c
T^001000^06^001009^231006
E^001000
*/