#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <math.h>
#include <unordered_set>

using namespace std;

const int modul = 1e9 + 7;

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    int count = 0;
    int i = 1, max = -1;
    while (i <= n) {
        int page;
        std::cin >> page;
        max = (page > max)? page: max;
        if (max == i) count++;
        i++;
    }
    std::cout << count << std::endl;
}