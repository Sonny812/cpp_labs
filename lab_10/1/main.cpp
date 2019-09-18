#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

int main() {
	std::vector<std::string> interrogative, exclamation;
	std::ifstream fs("source.txt");
	std::string text((std::istreambuf_iterator<char>(fs)),
					std::istreambuf_iterator<char>());

	std::regex re("(.+?[.!?]) ?");
	std::sregex_iterator iterator(text.begin(), text.end(), re);
	std::sregex_iterator end;

	while (iterator != end) {
		std::string match = iterator->str(1);
		char lastSymbol = match.back();
		if (lastSymbol == '?') {
			interrogative.push_back(match);
		}
		if (lastSymbol == '!') {
			exclamation.push_back(match);
		}
		iterator++;
	}

	std::cout << "Interrogative sentences:" << std::endl;
	for (auto sentence : interrogative) {
		std::cout << sentence << std::endl;
	}

	std::cout << "Exclamintation sentences:" << std::endl;
	for (auto sentence : exclamation) {
		std::cout << sentence << std::endl;
	}
}