#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
	int difference = 0;
	for (std::string line; std::getline(std::cin, line);) {
		std::stringstream quoted;
		quoted << std::quoted(line);
		difference += quoted.str().size() - line.size();
	}
	std::cout << difference << '\n';
}
