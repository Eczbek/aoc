#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
	int difference = 0;
	std::ifstream reader = std::ifstream("../input.txt");
	for (std::string line; std::getline(reader, line);) {
		std::stringstream quoted;
		quoted << std::quoted(line);
		difference += quoted.str().size() - line.size();
	}
	std::cout << difference << '\n';
}
