#include "pch.hpp"
#include "commands.hpp"
#include "HandleInput.hpp"
#include <cstdlib>
#include <cctype>
#include <queue>

/* --Commands for the shell-- */

// Useful function for here
bool isInt(const std::string& s) {
    if (s.empty()) return false;
    size_t start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    if (start == s.size()) return false;
    for (size_t i = start; i < s.size(); i++) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
}

// Print function
void print(std::vector<std::string> tokens) {
	for (std::string w : tokens) {
		std::cout << w << " ";
	}
	std::cout << std::endl;
}

// Evaluate calculations function
void eval(const std::vector<std::string> tokens) {
    if (tokens.empty()) {
        std::cout << "Invalid calculation" << std::endl;
        return;
    }

    std::queue<std::string> operations;
    for (const auto& token : tokens) {
        if (isInt(token) || token == "+" || token == "-" || token == "*" || token == "/") {
            operations.push(token);
        }
        else {
            std::cout << "Invalid calculation" << std::endl;
            return;
        }
    }

    double total = 0;
    std::string lastOp = "+"; 

    while (!operations.empty()) {
        std::string token = operations.front();
        operations.pop();

        if (isInt(token)) {
            double value = std::stod(token);

            if (lastOp == "+") total += value;
            else if (lastOp == "-") total -= value;
            else if (lastOp == "*") total *= value;
            else if (lastOp == "/") {
                if (value == 0) {
                    std::cout << "Invalid division by 0\n";
                    return;
                }
                total /= value;
            }
        }
        else {
            lastOp = token;
        }
    }

    std::cout << total << std::endl;
}

void clearTerminal() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");  
#else
    system("clear"); 
#endif
}

// Exit the terminal
void shellExit(std::vector<std::string> tokens) {
    if (tokens.empty()) std::exit(0);

    int exitCode;
    if (isInt(tokens[0])) {
        exitCode = std::stoi(tokens[0]);
    }
    else {
        std::cout << "Invalid exit code\n";
        return;
    }

    std::exit(exitCode);
}

// If else command works for ints only for now.
void ifStatement(std::vector < std::string> tokens) {
    if (tokens.empty()) {
        std::cout << "Invalid command argument\n";
        return;
    }

    if (tokens.size() < 4) {
        std::cerr << "Invalid if statement: missing arguments\n";
        return;
    }

    auto it = std::find(tokens.begin(), tokens.end(), "then");
    if (it == tokens.end()) {
        std::cout << "Invalid if statement no 'then' found\n";
        return;
    }

    bool hasElse = false;
    auto it2 = std::find(tokens.begin(), tokens.end(), "else");
    if (it2 != tokens.end()) {
        hasElse = true;
    }

    std::string arg1 = tokens[0];
    std::string op = tokens[1];
    std::string arg2 = tokens[2];

    std::vector<std::string> afterCommand;
    std::vector<std::string> elseBranch;

    if (hasElse) {
        // After the then and before the else
        afterCommand = std::vector<std::string>(it + 1, it2);

        // Else branch
        elseBranch = std::vector<std::string>(it2 + 1, tokens.end());
    }
    else {
        afterCommand = std::vector<std::string>(it + 1, tokens.end());
    }

    if (afterCommand.empty()) {
        std::cout << "No command given after 'then'\n";
        return;
    }

    bool cond = false;
    if (isInt(arg1) && isInt(arg2)) {
        int a = std::stoi(arg1);
        int b = std::stoi(arg2);
        if (op == "==") cond = (a == b);
        else if (op == "!=") cond = (a != b);
        else if (op == ">") cond = (a > b);
        else if (op == "<") cond = (a < b);
        else if (op == ">=") cond = (a >= b);
        else if (op == "<=") cond = (a <= b);
        else {
            std::cerr << "Invalid operator: " << op << '\n';
            return;
        }
    }
    else {
        std::cout << "Error only Int supported\n";
        return;
    }

    Lexer lexer;
    if (cond) {
        lexer.setTokens(afterCommand);
        lexer.readCommand();
    }
    else if (hasElse) {
        lexer.setTokens(elseBranch);
        lexer.readCommand();
    }
}
