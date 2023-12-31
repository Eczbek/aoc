#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <xieite/streams/read.hpp>

int main() {
	int x = 0;
	int y = 0;
	std::unordered_map<int, std::unordered_set<int>> grid { { x, { y } } };
	int houses = 1;
	std::string input;
	std::cin >> input;
	for (const char character : input) {
		switch (character) {
			case '>':
				++x;
				break;
			case '<':
				--x;
				break;
			case '^':
				++y;
				break;
			case 'v':
				--y;
				break;
		}
		if (!grid.contains(x)) {
			grid[x] = std::unordered_set<int>();
		}
		if (!grid.at(x).contains(y)) {
			grid.at(x).insert(y);
			++houses;
		}
	}
	std::cout << houses << '\n';
}
