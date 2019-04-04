#include <iostream>

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int u;
        std::cin >> u;
        if (u == 0) l = i;
        else r = i;
    }
    std::cout << ((l > r)? r + 1: l + 1) << std::endl;
}