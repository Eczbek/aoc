#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <xieite/streams/read.hpp>

int main() {
	int floor = 0;
	std::ifstream reader = std::ifstream("../input.txt");
	const std::string input = xieite::streams::read(reader);
	for (std::size_t i = 0; i < input.size(); ++i) {
		floor += (input[i] == '(') - (input[i] == ')');
		if (floor < 0) {
			std::cout << (i + 1) << '\n';
			break;
		}
	}
}
