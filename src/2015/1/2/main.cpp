#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <xieite/streams/read.hpp>

int main() {
	const std::string input = xieite::streams::read(std::ifstream("../input.txt"));
	int floor = 0;
	for (std::size_t i = 0; i < input.size(); ++i) {
		floor += (input[i] == '(') - (input[i] == ')');
		if (floor < 0) {
			std::cout << (i + 1) << '\n';
			break;
		}
	}
}
