#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <xieite/math/from_base.hpp>
#include <xieite/strings/is_digit.hpp>
#include <xieite/strings/lowercase.hpp>
#include <xieite/strings/split.hpp>

struct Wire {
	enum Gate {
		NONE,
		INPUT,
		NOT,
		OR,
		AND,
		RIGHT,
		LEFT
	};
	Wire* inputNode1 = nullptr;
	Wire* inputNode2 = nullptr;
	std::uint16_t inputValue1 = 0;
	std::uint16_t inputValue2 = 0;
	Wire::Gate gate = Wire::Gate::NONE;
	std::uint16_t value = 0;

	void update(std::unordered_set<Wire*>& updated) {
		if (updated.contains(this)) {
			return;
		}
		updated.insert(this);
		if (this->inputNode1) {
			this->inputNode1->update(updated);
		}
		if (this->inputNode2) {
			this->inputNode2->update(updated);
		}
		std::uint16_t input1 = this->inputNode1 ? this->inputNode1->value : this->inputValue1;
		std::uint16_t input2 = this->inputNode2 ? this->inputNode2->value : this->inputValue2;
		switch (this->gate) {
			case Wire::Gate::NONE:
				this->value = input1;
				break;
			case Wire::Gate::NOT:
				this->value = ~input1;
				break;
			case Wire::Gate::OR:
				this->value = input1 | input2;
				break;
			case Wire::Gate::AND:
				this->value = input1 & input2;
				break;
			case Wire::Gate::RIGHT:
				this->value = input1 >> input2;
				break;
			case Wire::Gate::LEFT:
				this->value = input1 << input2;
				break;
		}
	}
};

int main() {
	std::unordered_map<std::string, Wire> wires;
	for (std::string line; std::getline(std::cin, line);) {
		std::vector<std::string_view> slices = xieite::strings::split(line, ' ');
		if (slices.size() == 3) { // X -> Y
			Wire& wire = wires[std::string(slices[2])];
			if (xieite::strings::isDigit(slices[0][0])) {
				wire.inputValue1 = xieite::math::fromBase(slices[0], 10);
			} else {
				wire.inputNode1 = &wires[std::string(slices[0])];
			}
		} else if (slices.size() == 4) { // OP X -> Y
			Wire& wire = wires[std::string(slices[3])];
			wire.gate = Wire::Gate::NOT;
			if (xieite::strings::isDigit(slices[1][0])) {
				wire.inputValue1 = xieite::math::fromBase(slices[1], 10);
			} else {
				wire.inputNode1 = &wires[std::string(slices[1])];
			}
		} else { // X OP Y -> Z
			Wire& wire = wires[std::string(slices[4])];
			if (slices[1] == "OR") {
				wire.gate = Wire::Gate::OR;
			} else if (slices[1] == "AND") {
				wire.gate = Wire::Gate::AND;
			} else if (slices[1] == "RSHIFT") {
				wire.gate = Wire::Gate::RIGHT;
			} else {
				wire.gate = Wire::Gate::LEFT;
			}
			if (xieite::strings::isDigit(slices[0][0])) {
				wire.inputValue1 = xieite::math::fromBase(slices[0], 10);
			} else {
				wire.inputNode1 = &wires[std::string(slices[0])];
			}
			if (xieite::strings::isDigit(slices[2][0])) {
				wire.inputValue2 = xieite::math::fromBase(slices[2], 10);
			} else {
				wire.inputNode2 = &wires[std::string(slices[2])];
			}
		}
	}
	wires["b"].inputValue1 = 16076;
	std::unordered_set<Wire*> updated;
	wires["a"].update(updated);
	std::cout << wires["a"].value << '\n';
}
