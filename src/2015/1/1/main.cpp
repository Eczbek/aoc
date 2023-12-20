#include <fstream>
#include <iostream>
#include <iterator>
#include <string_view>

int main() {
	std::ifstream reader = std::ifstream("../input.txt");
	const std::string input = std::string(std::istreambuf_iterator<char>(reader), std::istreambuf_iterator<char>());
	int floor = 0;
	for (const char character : input) {
		floor += (character == '(') - (character == ')');
	}
	std::cout << floor << '\n';
}
