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
    std::string operate, o1, o2;
    uint32_t operand1 = 0x0;
    uint32_t operand2 = 0x0;

    file.open(argv[1]);

    //For each line in the file, the operator and each operand is picked out
    //The operands are cast into the uint32_t datatype 
    //Then the operator and operands are passed into the runCommand function
    while(getline(file, line)){
        std::istringstream ss(line);
        ss >> operate >> std::skipws 
           >> o1 >> std::skipws 
           >> o2;

        operand1 = static_cast<uint32_t>(std::stoul(o1, nullptr, 16));
        operand2 = static_cast<uint32_t>(std::stoul(o2, nullptr, 16));
        reader.runCommand(operate, operand1, operand2);
    }
    return 0;
}