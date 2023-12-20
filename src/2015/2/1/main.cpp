#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <xieite/math/from_base.hpp>
#include <xieite/math/minimum.hpp>
#include <xieite/strings/split.hpp>

int main() {
	std::ifstream reader = std::ifstream("../input.txt");
	int paper = 0;
	for (std::string line; std::getline(reader, line);) {
		std::vector<std::string_view> dimensions = xieite::strings::split(line, 'x');
		const int w = xieite::math::fromBase(dimensions[0], 10);
		const int h = xieite::math::fromBase(dimensions[1], 10);
		const int l = xieite::math::fromBase(dimensions[2], 10);
		const int x = w * h;
		const int y = h * l;
		const int z = l * w;
		paper += x * 2 + y * 2 + z * 2 + xieite::math::minimum(x, y, z);
	}
	std::cout << paper << '\n';
}
