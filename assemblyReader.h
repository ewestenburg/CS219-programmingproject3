#ifndef ASSEMBLY_READER
#define ASSEMBLY_READER

#include <map>
#include <string>

//This class contains a member of all the commands that can be run. And a function for each command. 
class AssemblyReader {
private:
    std::map<std::string, int> commandMap;

public:
    AssemblyReader();
    void initializeMap();
    void runCommand(std::string oper, uint32_t op1, uint32_t op2);
    void add(uint32_t op1, uint32_t op2);
    void bitwiseAnd(uint32_t op1, uint32_t op2);
    void asr(uint32_t op1, uint32_t op2);
    void lsr(uint32_t op1, uint32_t op2);
    void lsl(uint32_t op1, uint32_t op2);
    void bitwiseNot(uint32_t op1, uint32_t op2);
    void orr(uint32_t op1, uint32_t op2);
    void sub(uint32_t op1, uint32_t op2);
    void bitwiseXor(uint32_t op1, uint32_t op2);
};
//#include "assemblyReader.cpp"
#endif