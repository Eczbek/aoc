#include <fstream>
#include <iostream>
#include <xieite/streams/read.hpp>

int main() {
	int floor = 0;
	for (const char character : xieite::streams::read(std::ifstream("../input.txt"))) {
		floor += (character == '(') - (character == ')');
	}
	std::cout << floor << '\n';
}
