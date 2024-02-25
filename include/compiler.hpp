#ifndef PEACHCOMPILER_HPP
#define PEACHCOMPILER_HPP

#include <filesystem>

namespace fs = std::filesystem;

enum class CompilerCodes{
    kCompiledOk,
    kFailedWithErrors
};

class CompileProcess {
public:
    CompilerCodes CompileFile(const fs::path& filename, const fs::path& out_file, int flags);
private:
    // The flags regards how this file should be compiled
    int flags;
};

#endif //PEACHCOMPILER_HPP