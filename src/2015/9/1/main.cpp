#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <xieite/math/from_base.hpp>
#include <xieite/strings/split.hpp>

int main() {
	std::unordered_map<std::string, std::unordered_map<std::string, int>> distances;
	std::vector<std::string> route;
	for (std::string line; std::getline(std::cin, line);) {
		std::vector<std::string_view> slices = xieite::strings::split(line, ' ');
		distances[std::string(slices[0])][std::string(slices[2])] = distances[std::string(slices[2])][std::string(slices[0])] = xieite::math::fromBase(slices[4], 10);
	}
	for (const std::pair<std::string, std::unordered_map<std::string, int>>& distance : distances) {
		route.push_back(distance.first);
	}
	std::ranges::sort(route);
	int least = 0;
	do {
		int total = 0;
		for (std::size_t j = 1; j < route.size(); ++j) {
			total += distances[route[j - 1]][route[j]];
		}
		if (!least || (total < least)) {
			least = total;
		}
	} while (std::ranges::next_permutation(route).found);
	std::cout << least << '\n';
}
