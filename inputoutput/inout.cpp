#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <algorithm>

/**
 * @brief learn basic input stream utilities in c++ (cin)
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv) {
    int T;
    std::cin >> T;
    std::cin.ignore();
    std::cout << T << std::endl;
    for (int i = 0; i < T; i++) {
        std::string line;
        std::getline(std::cin, line);
        
        std::istringstream s(line);
        std::vector<int> vec;
        int input;
        while (s >> input) {
            vec.push_back(input);
        }
        std::for_each(vec.begin(), vec.end(), [](const int& n) {
            std::cout << n << " ";
        });
        std::cout << std::endl;
    }
    
}