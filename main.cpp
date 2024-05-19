#include <iostream>
#include <string>

bool checkInput(std::string& s) {
	if (s.size() != 7) {
		return 0;
	}
	for (char c : s) {
		if (c != '1' and c != '0') {
			return 0;
		}
	}
	return 1;
}

int main() {
	std::string code;
	std::cout << "Enter code: ";
	std::cin >> code;
	int n1 = 0, n2 = 0, n4 = 0, mistInd;
	if (!checkInput(code)) {
		std::cout << "Wrong input\n";
		return 0;
	}
	code.insert(code.begin(), ' ');
	for (int i = 1; i <= 7; i++) {
		if (i % 2) {
			n1 += code[i] == '1';
		}
		if (i == 2 or i == 7 or i % 3 == 0) {
			n2 += code[i] == '1';
		}
		if (i >= 4) {
			n4 += code[i] == '1';
		}
	}
	mistInd = n1 % 2 + n2 % 2 * 2 + n4 % 2 * 4;
	if (!mistInd) {
		std::cout << "No mistakes. ";
	}
	else {
		std::cout << "Mistake in position " << mistInd << ". ";
	}
	char mistSymbol = code[mistInd];
	code[mistInd] = mistSymbol == '1' ? '0' : '1';
	std::cout << "Correct number equals " << code[3] << code[5] << code[6] << code[7] << std::endl;
	return 0;
}
