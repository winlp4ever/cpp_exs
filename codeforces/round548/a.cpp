#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    std::getline(std::cin, s);
    int result(0);
    for (int i = 0; i < n; i++) {
        int k = s[i] - '0';
        if (k % 2 == 0) result += i + 1;
    }
    std::cout << result << std::endl;
}