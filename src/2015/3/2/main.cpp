#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <xieite/streams/read.hpp>

int main() {
	int x1 = 0;
	int y1 = 0;
	int x2 = x1;
	int y2 = y1;
	std::unordered_map<int, std::unordered_set<int>> grid { { x1, { y1 } } };
	int houses = 1;
	bool toggle = true;
	std::string input;
	std::cin >> input;
	for (const char character : input) {
		int& x = (toggle ? x1 : x2);
		int& y = (toggle ? y1 : y2);
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
		toggle = !toggle;
	}
	std::cout << houses << '\n';
}
