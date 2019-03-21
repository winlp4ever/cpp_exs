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
    int v[n];
    for (int i = 0; i < n; i++) std::cin >> v[i];
    int mx = v[n -1];
    long long result = mx;
    for (int i = n - 1; i > 0; i--) {
        mx = (mx > v[i - 1]) ? v[i - 1]: mx - 1;
        result += (mx > 0) ? mx: 0;
    } 
    std::cout << result << std::endl;
}