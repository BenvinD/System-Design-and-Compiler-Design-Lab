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
std::vector<std::string> macros;
int main()
{
char inp[1000];
std::ifstream data; data.open("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/input.txt");
freopen("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/output.txt","w", stdout);
std::cout<<"Name:   Benvin"<<std::endl<<"Reg No: URK19CS1060"<<std::endl<<std::endl;
bool flag = true;
std::vector<int> np;
if (data.is_open()){ 
    while (data.good()) {
        data.getline(inp,1000);
        std::string str(inp);
        std::istringstream iss(str);
        std::vector<std::string> cur;
        std::string word;
        while(iss >> word) 
            cur.push_back(word.c_str());
        if(flag)
        {
            if(std::find(cur.begin(), cur.end(), "main") != cur.end())
            {
                std::cout<<inp<<std::endl;
                flag = false;
                continue;
            }
            else if (cur[0]=="#define")
            {
                std::string chars = "()";
                macros.push_back(cur[1]);
                for (char c: chars) 
                  cur[2].erase(std::remove(cur[2].begin(), cur[2].end(), c), cur[2].end());
                macros.push_back(cur[2]);
                macros.push_back(cur[4]);
            }
            else
                std::cout<<inp<<std::endl;
        }
        else
        {
            if(std::find(macros.begin(), macros.end(), cur[0]) != macros.end())
            {
                std::vector<std::string>::iterator itr = std::find(macros.begin(), macros.end(), cur[0]);
                int index = std::distance(macros.begin(), itr);
                std::string chars = "()";
                for (char c: chars) 
                  cur[1].erase(std::remove(cur[1].begin(), cur[1].end(), c), cur[1].end());
                std::string tmp = macros[index+2];
                for(int i=0;i<macros[index+1].length();i++)
                {
                    if((macros[index+1][i]>='A'&&macros[index+1][i]<='Z')&&(cur[1][i]>='a'&&cur[1][i]<='z'))
                    std::replace(tmp.begin(), tmp.end(), macros[index+1][i], cur[1][i]);
                }
                tmp+=';';
                std::cout<<tmp<<std::endl;
            }
            else
            {
                std::cout<<inp<<std::endl;
            }
        }
    }
}
}
//g++ -std=c++17 /Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/Ex3.cpp -o /Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/Ex3 && /Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/Ex3
/*
Input:

#define ADD (X) ( X=X+X )
#define SUB (X) ( X=X-X )
#define MUL (X,Y) ( X=X*Y )
#include<stdio.h>
void main () 
{
int a = 10 ;
ADD (a) ;
SUB (b) ;
MUL (c,d) ;
}

Output:

Name:   Benvin
Reg No: URK19CS1060

#include<stdio.h>
void main () 
{
int a = 10 ;
a=a+a;
b=b-b;
c=c*d;
}
*/