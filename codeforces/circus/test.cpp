#include <iostream>
#include <string>


int main(int argc, char** argv) {
    std::string s = "101";

    std::cout << (s[1]&1) << std::endl;
    if ('0'&1) std::cout << "ok" << std::endl;
}