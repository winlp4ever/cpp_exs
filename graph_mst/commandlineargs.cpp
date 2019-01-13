#include <iostream>
#include <typeinfo>

int main(int argc, char** argv) {
    std::cout << "You have entered " << argc << "args" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
}