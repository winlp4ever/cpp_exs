#include <iostream>
#include <vector>
#include <typeinfo>

int main(int argc, char* argv[]) {
    const int h = 5;
    std::vector<int> p;
    p.push_back(int(5));
    int* u = &p[0];
    p.push_back(int(7));
    std::cout << *u << std::endl;
    std::cout << p[0] << std::endl;
    for (std::vector<int>::iterator it = p.begin() ; it != p.end(); it ++) {
        std::cout << typeid(it).name() << std::endl;
    }
    std::cout << typeid(p[0]).name() << std::endl;
}