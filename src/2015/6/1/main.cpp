#include <array>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <xieite/math/from_base.hpp>
#include <xieite/strings/split.hpp>

int main() {
	static constexpr std::size_t width = 1000;
	static constexpr std::size_t height = 1000;
	std::array<std::array<bool, height>, width> grid;
	for (std::size_t x = 0; x < width; ++x) {
		for (std::size_t y = 0; y < height; ++y) {
			grid[x][y] = false;
		}
	}
	std::ifstream reader = std::ifstream("../input.txt");
	for (std::string line; std::getline(reader, line);) {
		int action;
		if (line.starts_with("turn on")) {
			action = 0;
		} else if (line.starts_with("turn off")) {
			action = 1;
		} else {
			action = 2;
		}
		const std::vector<std::string_view> slices = xieite::strings::split(line, ' ');
		const std::vector<std::string_view> start = xieite::strings::split(slices[slices.size() - 3], ',');
		const std::vector<std::string_view> end = xieite::strings::split(slices[slices.size() - 1], ',');
		const std::size_t endX = xieite::math::fromBase(end[0], 10);
		const std::size_t endY = xieite::math::fromBase(end[1], 10);
		for (std::size_t x = xieite::math::fromBase(start[0], 10); x <= endX; ++x) {
			for (std::size_t y = xieite::math::fromBase(start[1], 10); y <= endY; ++y) {
				switch (action) {
					case 0:
						grid[x][y] = true;
						break;
					case 1:
						grid[x][y] = false;
						break;
					case 2:
						grid[x][y] = !grid[x][y];
						break;
				}
			}
		}
	}
	int count = 0;
	for (std::size_t x = 0; x < width; ++x) {
		for (std::size_t y = 0; y < height; ++y) {
			count += grid[x][y];
		}
	}
	std::cout << count << '\n';
}
