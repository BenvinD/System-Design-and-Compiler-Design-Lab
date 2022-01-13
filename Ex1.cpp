#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
std::ifstream data; data.open("input.txt");
freopen("output.txt", "w", stdout);
std::cout<<"Name:   Benvin"<<std::endl<<"Reg No: URK19CS1060"<<std::endl<<std::endl;
std::string mystr;
std::vector<std::string> keyword{"auto","main","break","case","char","const","continue","default","do",
                                "double","else","enum","extern","float","for","goto","if","int","long",
                                "register","return","short","signed","sizeof","static","struct","switch",
                                "typedef","union","unsigned","void","volatile","while"};
std::vector<std::string> puncuation{".",";",",","{","}","|","(",")"};
std::vector<std::string> opperator{"+","=","-","*","/","?",":","^","%","<=",">=","==","&&","||"};
std::vector<std::string> p_keyword,p_identifier,p_puncuation,p_operator;
int c_kw = 0 ,c_id =0 ,c_pu = 0 ,c_op = 0;
if (data.is_open()) {   
        while (data.good()) {
        data >> mystr;
        //std::cout << mystr <<std::endl;
        if(std::find(keyword.begin(), keyword.end(), mystr) != keyword.end())
            { 
                if(std::find(p_keyword.begin(), p_keyword.end(), mystr) == p_keyword.end())
                {
                c_kw++;
                p_keyword.push_back(mystr);
                }
            }
        else if(std::find(puncuation.begin(), puncuation.end(), mystr) != puncuation.end())
            {
                if(!(std::find(p_puncuation.begin(), p_puncuation.end(), mystr) != p_puncuation.end()))
                {
                c_pu++;
                p_puncuation.push_back(mystr);
                }
            }
         else if(std::find(opperator.begin(), opperator.end(), mystr) != opperator.end())
            {
                if(!(std::find(p_operator.begin(), p_operator.end(), mystr) != p_operator.end()))
                {
                c_op++;
                p_operator.push_back(mystr);
                }
            }
        else
        {
            if(!(std::find(p_identifier.begin(), p_identifier.end(), mystr) != p_identifier.end()))
            p_identifier.push_back(mystr);
        }
    }
}
std::cout<<"Number of Keyword Token: "<<c_kw<<" "<<std::endl;
for(int i=0;i<p_keyword.size();i++)
std::cout<<p_keyword[i]<<" ";
std::cout<<std::endl<<std::endl;
std::cout<<"Number of Punctuators Token: "<<c_pu<<" "<<std::endl;
for(int i=0;i<p_puncuation.size();i++)
std::cout<<p_puncuation[i]<<" ";
std::cout<<std::endl<<std::endl;
std::cout<<"Number of Operator Token: "<<c_op<<" "<<std::endl;
for(int i=0;i<p_operator.size();i++)
std::cout<<p_operator[i]<<" ";
std::cout<<std::endl<<std::endl;
std::cout<<"Number of Identifier Token: "<<c_op<<" "<<std::endl;
for(int i=0;i<p_identifier.size();i++)
std::cout<<p_identifier[i]<<" ";
std::cout<<std::endl<<std::endl;
std::cout<<"Total number of tokens is "<<c_id+c_kw+c_op+c_pu<<std::endl;
return 0;
}
 