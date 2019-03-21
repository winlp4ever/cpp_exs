#include <iostream>
#include <vector>

int getRoot(int* parents, int i) {
    while (parents[i] != i)
        i = parents[i];
    return i;
}

int main(int argc, char** argv) {
    int n, e; // n = nb of vertices, e = nb of edges
    std::cin >> n >> e;

    int nb_components = n;
    int* roots = new int[n];
    for (int i = 0; i < n; i++) roots[i] = i;
    for (int i = 0; i < e; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        int x = getRoot(roots, u);
        int y = getRoot(roots, v);
        if (x != y) {
            roots[x] = y;
            nb_components--;
        }
    }
    std::cout << "nb of connected components: " << nb_components << std::endl;
    delete[] roots;
}