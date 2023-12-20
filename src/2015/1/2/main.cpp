#include <fstream>
#include <iostream>
#include <iterator>
#include <string_view>

int main() {
	std::ifstream reader = std::ifstream("../input.txt");
	const std::string input = std::string(std::istreambuf_iterator<char>(reader), std::istreambuf_iterator<char>());
	int floor = 0;
	for (std::size_t i = 0; i < input.size(); ++i) {
		floor += (input[i] == '(') - (input[i] == ')');
		if (floor < 0) {
			std::cout << (i + 1) << '\n';
			break;
		}
	}
}
