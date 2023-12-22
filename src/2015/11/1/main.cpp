#include <cstddef>
#include <cstdint>
#include <iostream>
#include <xieite/math/from_base.hpp>
#include <xieite/math/to_base.hpp>

int main() {
	std::string input;
	std::cin >> input;
	std::uint64_t value = xieite::math::fromBase<std::uint64_t>(input, 26, "abcdefghijklmnopqrstuvwxyz");
	while (true) {
		++value;
		std::string password = xieite::math::toBase(value, 26, "abcdefghijklmnopqrstuvwxyz");
		if (password.contains('i') || password.contains('o') || password.contains('l')) {
			continue;
		}
		bool increasing = false;
		for (std::size_t i = 2; i < password.size(); ++i) {
			if (((password[i] - password[i - 2]) == 2) && ((password[i] - password[i - 1]) == 1)) {
				increasing = true;
			}
		}
		if (!increasing) {
			continue;
		}
		int pairs = 0;
		for (std::size_t i = 1; i < password.size(); ++i) {
			if (password[i] == password[i - 1]) {
				++pairs;
				++i;
			}
		}
		if (pairs > 1) {
			std::cout << password << '\n';
			break;
		}
	}
}
