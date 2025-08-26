#include "pch.hpp"
#include "HandleInput.hpp"
#include "commands.hpp"

std::vector<std::string> Parser::parseWords(const std::string& input) {
	std::vector<std::string> tokens;

	std::istringstream stream(input);
	std::string word;

	while (stream >> word) {
		tokens.push_back(word);
	}

	return tokens;
}

void Lexer::setTokens(const std::vector<std::string>& parsedTokens) {
	tokens = parsedTokens;
}

void Lexer::readCommand() {
	if (tokens.empty()) {
		std::cout << "Error : no command inputted" << std::endl;
		return;	
	}

	std::string command = tokens.front();
	tokens.erase(tokens.begin());

	if (command == "print") return print(tokens);
	else if (command == "eval") return eval(tokens);
	else if (command == "clear") return clearTerminal();
	else if (command == "exit") return shellExit(tokens);
	else if (command == "if") return ifStatement(tokens);

	else {
		std::cout << "Error : " << command << ", is not a valid command" << std::endl;
	}
}