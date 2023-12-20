#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main() {
	int nice = 0;
	std::ifstream reader = std::ifstream("../input.txt");
	for (std::string line; std::getline(reader, line);) {
		bool doubles = false;
		bool repeats = false;
		for (std::size_t i = 2; i < line.size(); ++i) {
			doubles |= line.substr(i).contains(line.substr(i - 2, 2));
			repeats |= line[i] == line[i - 2];
		}
		nice += doubles && repeats;
	}
	std::cout << nice << '\n';
}
