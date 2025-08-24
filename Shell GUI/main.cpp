#include "pch.hpp"
#include "init.hpp"
#include "HandleInput.hpp"
#include "shell.hpp"

// Declaration of WINW and WINH from pch.hpp
int WINW = 800;
int WINH = 600;

int main(int argc, char** argv) {
	// Testing IT WORKS
	Parser parser;
	Lexer lexer;

	std::cout << "Enter a command\n";
	while (true) {
		std::cout << "> ";

		std::string line;
		std::getline(std::cin, line);

		std::vector<std::string> tokens = parser.parseWords(line);
		lexer.setTokens(tokens);
		lexer.readCommand();
	}

	return 0;
}