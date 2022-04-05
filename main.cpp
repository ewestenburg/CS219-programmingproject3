//Author: Eric Ashton Westenburg
//Date: 3/3/22
//CS219 Programming Project #2

#include "assemblyReader.h"

#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char *argv[]){
    //Initializes the Reader
    //Then initializes all of the variables that will be used. 
    AssemblyReader reader;

    std::fstream file;
    std::string line;
    std::string operate, o1, o2, o3;
    uint32_t operand1 = 0x0;
    uint32_t operand2 = 0x0;

    file.open(argv[1]);

    //For each line in the file, the operator and each operand is picked out
    //The operands are cast into the uint32_t datatype 
    //Then the operator and operands are passed into the runCommand function
    while(getline(file, line)){
        o3 = "";
        std::istringstream ss(line);
        ss >> operate >> std::skipws 
           >> o1 >> std::skipws 
           >> o2 >> std::skipws
           >> o3;

        //Convert Operater and Register names to ALL CAPS
        for(char& c: operate){
            if(c >= 96){
                c = c - 32;
            } 
        }
        for(char& c: o1){
            if(c >= 96){
                c = c - 32;
            }             
        }
        for(char& c: o2){
            if(c >= 96 && c != 'x'){
                c = c - 32;
            }             
        }
        for(char& c: o3){
            if(c >= 96){
                c = c - 32;
            }             
        }
        std::cout << operate << " " << o1 << " " << o2 << " " << o3  << "\n";
        reader.runCommand(operate, o1, o2, o3);
        std::cout << "----------------" << '\n';
    }
    return 0;
}