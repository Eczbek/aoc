#include <fstream>
#include <iostream>
#include <string>
#include <xieite/math/to_base.hpp>
#include <xieite/strings/hash_md5.hpp>

int main() {
	std::string input;
	std::ifstream("../input.txt") >> input;
	int number = 0;
	while (!xieite::strings::hashMd5(input + xieite::math::toBase(number, 10)).starts_with("00000")) {
		++number;
	}
	std::cout << number << '\n';
}
