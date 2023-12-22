#include <cstddef>
#include <iostream>
#include <string>

int main() {
	int nice = 0;
	for (std::string line; std::getline(std::cin, line);) {
		if (line.contains("ab") || line.contains("cd") || line.contains("pq") || line.contains("xy")) {
			continue;
		}
		bool doubles = false;
		int vowels = 0;
		for (std::size_t i = 0; i < line.size(); ++i) {
			doubles |= i && (line[i] == line[i - 1]);
			vowels += std::string_view("aeiou").contains(line[i]);
		}
		nice += doubles && (vowels > 2);
	}
	std::cout << nice << '\n';
}
