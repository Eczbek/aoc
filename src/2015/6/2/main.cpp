#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <xieite/math/from_base.hpp>
#include <xieite/strings/split.hpp>

int main() {
	static constexpr std::size_t width = 1000;
	static constexpr std::size_t height = 1000;
	std::array<std::array<int, height>, width> grid;
	for (std::size_t x = 0; x < width; ++x) {
		for (std::size_t y = 0; y < height; ++y) {
			grid[x][y] = 0;
		}
	}
	for (std::string line; std::getline(std::cin, line);) {
		int action;
		if (line.starts_with("turn on")) {
			action = 1;
		} else if (line.starts_with("turn off")) {
			action = -1;
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
				grid[x][y] = std::max(0, grid[x][y] + action);
			}
		}
	}
	long long int count = 0;
	for (std::size_t x = 0; x < width; ++x) {
		for (std::size_t y = 0; y < height; ++y) {
			count += grid[x][y];
		}
	}
	std::cout << count << '\n';
}
