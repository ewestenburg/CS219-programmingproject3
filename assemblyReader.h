#ifndef ASSEMBLY_READER
#define ASSEMBLY_READER

#include <map>
#include <string>

//This class contains a member of all the commands that can be run. And a function for each command. 
class AssemblyReader {
private:
    //Commands
    std::map<std::string, int> commandMap;

    //Registers
    std::map<std::string, uint32_t> registers;

public:
    AssemblyReader();
    void initializeMap();
    void initializeRegisters();
    void runCommand(std::string oper, std::string r1, std::string r2, std::string r3);
    uint32_t add(std::string r1, std::string r2);
    uint32_t bitwiseAnd(std::string r1, std::string r2);
    uint32_t asr(std::string r1, std::string r2);
    uint32_t lsr(std::string r1, std::string r2);
    uint32_t lsl(std::string r1, std::string r2);
    uint32_t bitwiseNot(std::string r1, std::string r2);
    uint32_t orr(std::string r1, std::string r2);
    uint32_t sub(std::string r1, std::string r2);
    uint32_t bitwiseXor(std::string r1, std::string r2);
    void mov(std::string r0, uint32_t op);
};
//#include "assemblyReader.cpp"
#endif