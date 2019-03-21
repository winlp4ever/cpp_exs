#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char** argv) {
    std::string s, p;
    std::getline(std::cin, s);
    std::getline(std::cin, p);
    std::istringstream s_p(p);
    std::vector<std::string> splt_p;
    std::string token;
    while (std::getline(s_p, token, '*')) splt_p.push_back(token);
    std::cout << s << std::endl;
    for (int i = 0; i < splt_p.size(); i++) std::cout << splt_p[i] << std::endl;
}