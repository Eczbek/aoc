#include <fstream>
#include <iostream>
#include <xieite/streams/read.hpp>

int main() {
	int floor = 0;
	std::ifstream reader = std::ifstream("../input.txt");
	for (const char character : xieite::streams::read(reader)) {
		floor += (character == '(') - (character == ')');
	}
	std::cout << floor << '\n';
}
