#include <iostream>
#include <string>

int main() {
	int floor = 0;
	std::string input;
	std::cin >> input;
	for (const char character : input) {
		floor += (character == '(') - (character == ')');
	}
	std::cout << floor << '\n';
}
