#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
    int n; 
    std::cin >> n;
    int sum = 0;
    for (int i = 2; i < n; i++) {
        sum += i * (i + 1);
    }
    std::cout << sum << std::endl;
}