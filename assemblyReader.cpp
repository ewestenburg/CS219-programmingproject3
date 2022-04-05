#include "assemblyReader.h"

#include <iostream>
#include <cstring>
#include <cmath>

//AssemblyReader Constructor
AssemblyReader::AssemblyReader(){
    initializeMap();
    initializeRegisters();
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
    commandMap.insert({"MOV", 9});
}

//Inializes the registers to 0x0
void AssemblyReader::initializeRegisters(){
    registers.insert({"R0", 0x0});
    registers.insert({"R1", 0x0});
    registers.insert({"R2", 0x0});    
    registers.insert({"R3", 0x0});
    registers.insert({"R4", 0x0});
    registers.insert({"R5", 0x0});
    registers.insert({"R6", 0x0});
    registers.insert({"R7", 0x0});
}

//Uses the map to figure out which command is trying to be run and executes that command.
//template<class T>
void AssemblyReader::runCommand(std::string oper, std::string r0, std::string r1, std::string r2){
    int operKey = commandMap[oper];

    switch (operKey){
        case 0:
            registers[r0] = add(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 1:
            registers[r0] = bitwiseAnd(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 2:
            registers[r0] = asr(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 3:
            registers[r0] = lsr(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 4:
            registers[r0] = lsl(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 5:
            registers[r0] = bitwiseNot(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 6:
            registers[r0] = orr(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 7:
            registers[r0] = sub(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 8:
            registers[r0] = bitwiseXor(r1, r2);
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
        case 9:
            mov(r0, std::stoul(r1, nullptr, 16));
            std::cout << r0 << " = " << registers[r0] << '\n';
            break;
    }
}

//Adds two operands and prints result
uint32_t AssemblyReader::add(std::string r1, std::string r2){
    std::cout << std::hex << registers[r1] << " + " << std::hex << registers[r2] << " = " << registers[r1] + registers[r2] << "\n";
    return registers[r1] + registers[r2];
}

//Bitwise And on two operands
uint32_t AssemblyReader::bitwiseAnd(std::string r1, std::string r2){
    std::cout << std::hex << registers[r1] << " & " << std::hex << registers[r2] << " = " << (registers[r1] & registers[r2]) << "\n";
    return (registers[r1] & registers[r2]);
}

//Logical shift right on first operand
uint32_t AssemblyReader::lsr(std::string r1, std::string r2){
    std::cout << "LSR " << std::hex << registers[r1] << " = " << (registers[r1] >> 1) << "\n";
    return (registers[r1] >> 1);
}

//Because the integers are unsigned the >> is automatically a LSR. 
//Arithmetic shift right on first operand. 
uint32_t AssemblyReader::asr(std::string r1, std::string r2){
    uint32_t temp = (registers[r1] >> 1);

    //If the 31st bit is 1 then add 2^31 to the result
    if(registers[r1] >= 2147483648){
        temp = temp + 2147483648;
    }
    return temp;
}

//Logical shift left on first operand
uint32_t AssemblyReader::lsl(std::string r1, std::string r2){
    std::cout << "LSL " << std::hex << registers[r1] << " = " << (registers[r1] << 1) << "\n";
    return (registers[r1] << 1);
}

//Bitwise Not on first operand
uint32_t AssemblyReader::bitwiseNot(std::string r1, std::string r2){
    std::cout << "NOT " << std::hex << registers[r1] << " = " << ~registers[r1] << "\n";
    return ~registers[r1];
}

//Bitwise or on two operands
uint32_t AssemblyReader::orr(std::string r1, std::string r2){
    std::cout << std::hex << registers[r1] << " | " << std::hex << registers[r2] << " = " << (registers[r1] | registers[r2]) << "\n";
    return (registers[r1] | registers[r2]);
}

//Subtracts second operand from the first operand
uint32_t AssemblyReader::sub(std::string r1, std::string r2){
    std::cout << std::hex << registers[r1] << " - " << std::hex << registers[r2] << " = " << (registers[r1] - registers[r2]) << "\n";
    return (registers[r1] - registers[r2]);
}

//Bitwise xor on two operands
uint32_t AssemblyReader::bitwiseXor(std::string r1, std::string r2){
    std::cout << std::hex << registers[r1] << " ^ " << std::hex << registers[r2] << " = " << (registers[r1] ^ registers[r2]) << "\n";
    return (registers[r1] ^ registers[r2]);
}

//Changes value of register
void AssemblyReader::mov(std::string r0, uint32_t op){
    registers[r0] = op; 
}
