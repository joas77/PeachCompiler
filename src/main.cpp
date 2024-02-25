#include <iostream>
#include "compiler.hpp"

int main()
{
    std::cout << "Hello Peach C Compiler!" << std::endl;
    auto compiler = CompileProcess();
    auto compileResult = compiler.CompileFile("test", "test", 0);

    if(compileResult == CompilerCodes::kCompiledOk){
        std::cout << "Everythin compiled fine!" << std::endl;
    } else if(compileResult == CompilerCodes::kFailedWithErrors) {
        std::cout << "Compile Failed" << std::endl;
    } else {
        std::cout << "Unknown responce for compile time" << std::endl;
    }

    return 0;
}