#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main() {
	int difference = 0;
	std::ifstream reader = std::ifstream("../input.txt");
	for (std::string line; std::getline(reader, line);) {
		difference += 2;
		for (std::size_t i = 1; i < line.size(); ++i) {
			if (line[i - 1] == '\\') {
				switch (line[i]) {
					case '\\':
					case '\"':
						++difference;
						++i;
						break;
					case 'x':
						difference += 3;
						i += 3;
						break;
				}
			}
		}
	}
	std::cout << difference << '\n';
}
