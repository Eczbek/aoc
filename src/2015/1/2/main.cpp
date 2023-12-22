#include <cstddef>
#include <iostream>
#include <string>

int main() {
	int floor = 0;
	std::string input;
	std::cin >> input;
	for (std::size_t i = 0; i < input.size(); ++i) {
		floor += (input[i] == '(') - (input[i] == ')');
		if (floor < 0) {
			std::cout << (i + 1) << '\n';
			break;
		}
	}
}
