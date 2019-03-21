#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

struct edge {
    int x, y, color;
    edge(int u1, int u2): x(u1), y(u2), color(-1) {};
    ~edge() {};
};

int main(int argc, char** argv) {
    int n, k;
    std::cin >> n >> k;
    std::cin.ignore();
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = 0;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        v[x] ++;
        v[y] ++;
    }
    std::sort(v.rbegin(), v.rend());
    int r = v[k];
    std::cout << r << std::endl;
}