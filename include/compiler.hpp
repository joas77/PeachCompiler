#ifndef PEACHCOMPILER_HPP
#define PEACHCOMPILER_HPP

#include <filesystem>
#include <variant>

namespace fs = std::filesystem;

struct Position {
    int line;
    int column;
    fs::path filename;
};

enum class TokenType{
    kIdentifier,
    kKeyword,
    kOperator,
    kSymbol,
    kNumber,
    kString,
    kComment,
    kNewLine
};

struct Token {
    TokenType type;
    int flags;

    //TODO: specify the value that holds the token as std::variant
    //std::variant<char> value;
    // True if there is a whitespace between the token and the next token
    // i.e * a for operator token * would mean whitespace would be set for token "a"
    bool whitespace;

    std::string between_brackets;
};

enum class CompilerCodes{
    kCompiledOk,
    kFailedWithErrors
};

class CompileProcess {
public:
    CompilerCodes CompileFile(const fs::path& filename, const fs::path& out_file, int flags);
private:
    // The flags regards how this file should be compiled
    int flags_;
};

#endif //PEACHCOMPILER_HPP