#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int cas(int l, std::string s) {
    int b = 0, e = 0;
    while (b < l - 1 && s[b] == '<') b++;
    while (e < l - 1 && s[l - 1 - e] == '>') e++;
    return (b > e)? e: b;
}

int main(int argc, char** argv) {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int l;
        std::cin >> l;
        std::cin.ignore();
        std::string s;
        std::getline(std::cin, s);
        std::cout << cas(l, s) << std::endl;
    }
}