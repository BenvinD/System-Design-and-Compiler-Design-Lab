#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    char inp[1000];
    std::ifstream data; data.open("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/asmloader.txt");
    freopen("/Users/benvindavid/Desktop/Code/System_Design_and_Compiler_Design_Lab/output.txt","w", stdout);
    std::cout<<"Name:   Benvin"<<std::endl<<"Reg No: URK19CS1060"<<std::endl<<std::endl;
    bool flag = true;
    if(data.is_open()){ 
        while(data.good()){
            data.getline(inp,1000);
            std::string str(inp);
            std::istringstream iss(str);
            if(str[0]=='T')
            {
                std::vector<std::string> tok;
                std::stringstream check1(str);
                std::string inter; 
                while(getline(check1, inter, '^'))
                    tok.push_back(inter);
                int add = 0;
                for(int i = 0; i < tok.size(); i++)
                    if(tok[i][0]=='T')
                    {
                        add = stoi(tok[i+1]);
                        i++;
                    }
                    else if(tok[i].length()>2)
                        for(int j = 0; j <tok[i].length();j+=2)
                        {
                            std::cout<<std::setfill ('0') << std::setw(6)<<add<<" "<<tok[i][j]<<tok[i][j+1]<<std::endl;
                            add++;
                        }
            }
        }
    }
}