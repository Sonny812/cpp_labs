#include <iostream>
#include <string>
#include <regex>
#include <cstring>

int main() {
    std::cout << "Enter string with spaces: " << std::endl;

    std::cout << "1. Using std::string" << std::endl;
    std::string str;
    std::getline(std::cin, str);
    std::smatch match;
    std::regex_search(str, match, std::regex("(.+) "));
    std::cout << match.str();

    std::cout << std::endl << "2. Using C-strings" << std::endl;
    char cstr[200];
    std::cin.getline(cstr, 200);
    for (int i = strlen(cstr); i >= 0; i--) {
        if (cstr[i] == ' ') {
            cstr[i] = '\0';
            break;
        }
    }
    std::cout << cstr << std::endl;
}