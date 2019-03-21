#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief complexity O(mn(log m + log n))
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char** argv) {
    int m, n;
    std::cin >> m >> n;
    
    int tab[m][n];
    std::vector<int> R[m], C[n];
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) {
            std::cin >> tab[i][j];
            R[i].push_back(tab[i][j]);
            C[j].push_back(tab[i][j]);
        }
    
    for (int i = 0; i < m; i++) {
        std::sort (R[i].begin(), R[i].end());
        R[i].resize (std::unique (R[i].begin(), R[i].end()) - R[i].begin());
    }

    for (int j = 0; j < n; j++) {
        std::sort (C[j].begin(), C[j].end());
        C[j].resize (std::unique (C[j].begin(), C[j].end()) - C[j].begin());
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            int r = std::lower_bound (R[i].begin(), R[i].end(), tab[i][j]) - R[i].begin();
            int c = std::lower_bound (C[j].begin(), C[j].end(), tab[i][j]) - C[j].begin();
            std::cout << (std::max (r, c) + std::max(R[i].size() - r, C[j].size() - c));
            if (j == n - 1) std::cout << std::endl;
            else std::cout << " ";
    }
}