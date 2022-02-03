/*#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <regex>
#include <map>

int main()
{
char inp[1000];
std::ifstream data; data.open("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/input.txt");
freopen("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/output.txt","w", stdout);
std::cout<<"Name:   Benvin"<<std::endl<<"Reg No: URK19CS1060"<<std::endl<<std::endl;
std::string mystr;
std::vector<std::string> datatype {"auto","char","double","float","int","long","short"};
std::vector<std::string> id,dt,rt,iv;
std::multimap<std::string,std::string> tp;
std::multimap<std::string,std::string>::iterator it;
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
            if((std::find(cur.begin(), cur.end(), "(") != cur.end())&&std::find(cur.begin(), cur.end(), ")") != cur.end())
            {
                if(std::find(datatype.begin(), datatype.end(), cur[0]) != datatype.end())
                rt.push_back(cur[0]);
                else
                {
                std::cout<<"Syntax Error"<<std::endl;
                break;
                }
                id.push_back(cur[1]);
                int nop = 0;
                for(int i=3;i<cur.size();i++)
                {
                    if(std::regex_match(cur[i], std::regex("^[A-Za-z]+$")) && std::find(id.begin(), id.end(), cur[i]) == id.end())
                    if(std::find(datatype.begin(), datatype.end(), cur[0]) != datatype.end())
                    {
                        nop++;
                        tp.insert(std::pair<std::string,std::string>(cur[1],cur[i]));
                    }
                }
                dt.push_back(NULL);
                np.push_back(nop);
                iv.push_back(NULL);
            }
            else
            {   
                std::string datat;
                if(std::find(datatype.begin(), datatype.end(), cur[0]) != datatype.end())
                datat = cur[0];
                else
                {
                std::cout<<"Syntax Error"<<std::endl;
                break;
                }
                for(int i=1;i<cur.size()-1;i++)
                {
                    if(std::regex_match(cur[i], std::regex("^[A-Za-z]+$")) && std::find(id.begin(), id.end(), cur[i]) == id.end())
                    {
                        if(cur[i+1]=="=")
                        {
                            id.push_back(cur[i]);
                            dt.push_back(datat);
                            rt.push_back(NULL);
                            iv.push_back(cur[i+2]);
                            tp.insert(std::pair<std::string,std::string>(NULL,NULL));
                            np.push_back(0);
                            std::cout<<"tHere"<<std::endl;
                        }
                        else
                        {
                            id.push_back(cur[i]);
                            dt.push_back(datat);
                            rt.push_back(NULL);
                            iv.push_back(0);
                            tp.insert(std::pair<std::string,std::string>(NULL,NULL));
                            np.push_back(0);
                            std::cout<<"Here"<<std::endl;
                        }
                    }
                }
            }
    }
}
it=tp.begin();
std::cout<<std::left<<std::setw(5)<<"ID"<<std::left<<std::setw(15)<<"Data Type"<<std::left<<std::setw(15)<<"Return Type"<<std::left<<std::setw(20)<<"Initial Value"<<std::left<<std::setw(25)<<"Number of Parameters"<<std::left<<std::setw(25)<<"Types of Parameter"<<std::endl;
for(int i=0;i<id.size();i++)
{
std::cout<<std::left<<std::setw(5)<<id[i]<<std::left<<std::setw(15)<<dt[i]<<std::left<<std::setw(15)<<rt[i]<<std::left<<std::setw(20)<<iv[i]<<std::left<<std::setw(25)<<np[i]<<std::left<<std::setw(25)<<std::endl;
it++;
}
}*/

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <regex>
#include <iomanip>

std::vector<std::string>data_type{"auto","void","int","float","double","char","string"};
std::vector<std::string> punc{";","{","}","(",")","=",","};
int main(){
    char inp[1000];
std::ifstream data; data.open("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/input.txt");
freopen("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/output.txt","w", stdout);
    std::cout<<"Name:   Benvin"<<std::endl<<"Reg No: URK19CS1060"<<std::endl<<std::endl;
    if (data.is_open()){   
    while (data.good()) {
        data.getline(inp,1000);
        std::string str(inp);
        std::istringstream iss(str);
        std::vector<std::string> cur;
        std::string word;
        while(iss >> word) 
        cur.push_back(word);
        std::string local_dt;
        std::string local_rt;
        std::string func_id;
        std::vector<std::string> local_id,local_iv,para,para_id;
        for(int i=0;i<cur.size();i++){
            if(cur[i+1]!=";"){
                if(std::find(data_type.begin(), data_type.end(), cur[i]) != data_type.end()){
                local_dt=cur[i];
                }
                else if(std::regex_match(cur[i], std::regex("^[A-Za-z]+$"))){
                    local_id.push_back(cur[i]);
                    if(cur[i+1]== "=")
                    local_iv.push_back(cur[i+2]);
                    else
                    local_iv.push_back("0");
                }
                }
            else{
                if(cur[i-1]!="="){
                    local_id.push_back(cur[i]);
                }
                for(int i=0;i<local_id.size();i++){
                std::cout<<std::left<<std::setw(5)<<"id: "<<std::left<<std::setw(15)<<local_id[i]<<" "<<std::left<<std::setw(10)<<"data type: "<<std::left<<std::setw(15)<<local_dt<<" "<<std::left<<std::setw(15)<<"initial values: "<<std::left<<std::setw(15)<<local_iv[i]<<std::endl;
            }
            local_dt="";
            local_id.empty();
            }
            int np=0;
            if(cur[i]!=")"){
                if(std::find(data_type.begin(), data_type.end(), cur[i]) != data_type.end()){
                para.push_back(cur[i]);
                para_id.push_back(cur[i+1]);
                np++;
                }
             }
            else if(cur[i]==")"){
                std::cout<<std::left<<std::setw(5)<<"id: "<<std::left<<std::setw(15)<<para_id[0]<<" "<<std::left<<std::setw(10)<<"return type: "<<std::left<<std::setw(14)<<para[0];
                std::cout<<std::left<<std::setw(20)<<"Number of Parameters: "<<para.size()-1;
                std::cout<<std::left<<std::setw(15)<<" Parameters: ";
                for(int i=1;i<para.size();i++){
                    std::cout<<std::left<<std::setw(10)<<para[i]<<" "<<para_id[i]<<" ";
                }
                std::cout<<std::endl;
                local_rt="";
                func_id="";
                para.empty();
                para_id.empty();
            }
        }
    }
    } 
}
//g++ -std=c++17 /Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/Ex2.cpp -o /Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/Ex2 && /Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/Ex2


/*
input:
int a , b = 5 ;
char c = ’d’ ;
double Add ( double x , double y ) 
int sub ( int g )
int k = 8 ;

output:
Name:   Benvin
Reg No: URK19CS1060

id:  a               data type: int             initial values: 0              
id:  b               data type: int             initial values: 5              
id:  c               data type: char            initial values: ’d’        
id:  Add             return type: double        Number of Parameters: 2 Parameters:   double     x double     y 
id:  sub             return type: int           Number of Parameters: 1 Parameters:   int        g 
id:  k               data type: int             initial values: 8              
*/