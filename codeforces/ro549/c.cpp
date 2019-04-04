#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    int parents[n];
    int unresp[n];
    for (int i = 0; i < n; i++) 
        std::cin >> parents[i] >> unresp[i];
    for (int i = 0; i < n; i++) {
        if (unresp[i] == 0) {
            int u = parents[i];
            if (u != -1 && unresp[u - 1] == 1) {
                unresp[u - 1] = 2;
            }
        }
    }
    int l = 0;
    for (int i = 0; i < n; i++) 
        if (unresp[i] == 1) { 
            std::cout << i + 1 << " ";
            l++;
        }
    if (l == 0) std::cout << -1;
    std::cout << std::endl;
    return 0;
}