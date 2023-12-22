#include <cstddef>
#include <iostream>
#include <string>

int main() {
	std::string input;
	std::cin >> input;
	for (int i = 0; i < 50; ++i) {
		char current = input[0];
		int count = 1;
		std::string result;
		for (std::size_t i = 1; i < input.size(); ++i) {
			if (input[i] == current) {
				++count;
			} else {
				result += std::to_string(count) + current;
				current = input[i];
				count = 1;
			}
		}
		result += std::to_string(count) + current;
		input = result;
	}
	std::cout << input.size() << '\n';
}
