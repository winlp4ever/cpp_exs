#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
    std::cout << "Write something:" << std::endl;

    std::string s;
    std::getline(std::cin, s);
    std::istringstream stream(s);
    std::vector<std::string> tokens;
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    std::for_each(tokens.begin(), tokens.end(), [](const std::string& u) {
        std::cout << u << std::endl;
    });
    std::cerr << "funny though" << std::endl;
}