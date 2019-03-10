#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cxxabi.h>
#include <typeinfo>


int main(int argc, char** argv) {
    std::ifstream f("./input.txt");
    std::string line;
    if (f.is_open()) {
        while (std::getline(f, line)) {
            std::cout << line << std::endl;
        }
    }
    f.close();

    unsigned int u;
    std::cout << typeid(u).name() << std::endl;
}