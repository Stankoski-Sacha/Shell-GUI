#include "pch.hpp"
#include "commands.hpp"

/* --Commands for the shell-- */

// Print function
void print(std::vector<std::string> tokens) {
	for (std::string w : tokens) {
		std::cout << w << " ";
	}
	std::cout << std::endl;
}

// Evaluate calculations function
void eval(std::vector<std::string> tokens) {

}
