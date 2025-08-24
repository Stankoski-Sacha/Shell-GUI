#pragma once
#include "pch.hpp"
#include "commands.hpp"

class Parser {
public:
    std::vector<std::string> parseWords(const std::string& input);
};

class Lexer {
private:
    std::vector<std::string> tokens;

public:
    void setTokens(const std::vector<std::string>& parsedTokens);

    void readCommand();
};
