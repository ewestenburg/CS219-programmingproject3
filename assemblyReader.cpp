#include "assemblyReader.h"

#include <iostream>
#include <cstring>
#include <cmath>

//AssemblyReader Constructor
AssemblyReader::AssemblyReader(){
    initializeMap();
}

//Initializes the commands into the map
void AssemblyReader::initializeMap(){
    commandMap.insert({"ADD", 0});
    commandMap.insert({"AND", 1});
    commandMap.insert({"ASR", 2});    
    commandMap.insert({"LSR", 3});
    commandMap.insert({"LSL", 4});
    commandMap.insert({"NOT", 5});
    commandMap.insert({"ORR", 6});
    commandMap.insert({"SUB", 7});
    commandMap.insert({"XOR", 8});
}

//Uses the map to figure out which command is trying to be run and executes that command.
void AssemblyReader::runCommand(std::string oper, uint32_t op1, uint32_t op2){
    int operKey = commandMap[oper];

    switch (operKey){
        case 0:
            add(op1, op2);
            break;
        case 1:
            bitwiseAnd(op1, op2);
            break;
        case 2:
            asr(op1, op2);
            break;
        case 3:
            lsr(op1, op2);
            break;
        case 4:
            lsl(op1, op2);
            break;
        case 5:
            bitwiseNot(op1, op2);
            break;
        case 6:
            orr(op1, op2);
            break;
        case 7:
            sub(op1, op2);
            break;
        case 8:
            bitwiseXor(op1, op2);
            break;
    }
}

//Adds two operands and prints result
void AssemblyReader::add(uint32_t op1, uint32_t op2){
    std::cout << std::hex << op1 << " + " << std::hex << op2 << " = " << op1 + op2 << "\n";
}

//Bitwise And on two operands
void AssemblyReader::bitwiseAnd(uint32_t op1, uint32_t op2){
    std::cout << std::hex << op1 << " & " << std::hex << op2 << " = " << (op1 & op2) << "\n";
}

//Logical shift right on first operand
void AssemblyReader::lsr(uint32_t op1, uint32_t op2){
    std::cout << "LSR " << std::hex << op1 << " = " << (op1 >> 1) << "\n";
}

//Because the integers are unsigned the >> is automatically a LSR. 
//Arithmetic shift right on first operand. 
void AssemblyReader::asr(uint32_t op1, uint32_t op2){
    //x equals the first bit set to 1. I.e x=3 if op1=0101
    int x = (int)log2(op1)+1;
    //Produces a number that is 1 at the xth bit and 0 every else
    uint32_t mask = pow(2, x-1);

    //op2 is set to the 1 Bit LSR of op1
    op2 = (op1 >> 1);

    //The ASR is calculated by taking the OR of the 1 Bit LSR of op1 and the mask.
    std::cout << "ASR " << std::hex << op1 << " = " << (op2 | mask) << "\n";
}

//Logical shift left on first operand
void AssemblyReader::lsl(uint32_t op1, uint32_t op2){
    std::cout << "LSL " << std::hex << op1 << " = " << (op1 << 1) << "\n";
}

//Bitwise Not on first operand
void AssemblyReader::bitwiseNot(uint32_t op1, uint32_t op2){
    std::cout << "NOT " << std::hex << op1 << " = " << ~op1 << "\n";
}

//Bitwise or on two operands
void AssemblyReader::orr(uint32_t op1, uint32_t op2){
    std::cout << std::hex << op1 << " | " << std::hex << op2 << " = " << (op1 | op2) << "\n";
}

//Subtracts second operand from the first operand
void AssemblyReader::sub(uint32_t op1, uint32_t op2){
    std::cout << std::hex << op1 << " - " << std::hex << op2 << " = " << (op1 - op2) << "\n";
}

//Bitwise xor on two operands
void AssemblyReader::bitwiseXor(uint32_t op1, uint32_t op2){
    std::cout << std::hex << op1 << " ^ " << std::hex << op2 << " = " << (op1 ^ op2) << "\n";
}
