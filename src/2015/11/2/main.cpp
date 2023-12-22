#include <cstddef>
#include <cstdint>
#include <iostream>
#include <xieite/math/from_base.hpp>
#include <xieite/math/to_base.hpp>

int main() {
	std::string password;
	std::cin >> password;
	std::uint64_t value = xieite::math::fromBase<std::uint64_t>(password, 26, "abcdefghijklmnopqrstuvwxyz");
	for (int i = 0; i < 2; ++i) {
		while (true) {
			++value;
			password = xieite::math::toBase(value, 26, "abcdefghijklmnopqrstuvwxyz");
			if (password.contains('i') || password.contains('o') || password.contains('l')) {
				continue;
			}
			bool increasing = false;
			for (std::size_t j = 2; j < password.size(); ++j) {
				if (((password[j] - password[j - 2]) == 2) && ((password[j] - password[j - 1]) == 1)) {
					increasing = true;
				}
			}
			if (!increasing) {
				continue;
			}
			int pairs = 0;
			for (std::size_t j = 1; j < password.size(); ++j) {
				if (password[j] == password[j - 1]) {
					++pairs;
					++j;
				}
			}
			if (pairs > 1) {
				break;
			}
		}
	}
	std::cout << password << '\n';
}
