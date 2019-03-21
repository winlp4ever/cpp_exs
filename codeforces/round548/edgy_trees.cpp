#include <iostream>
#include <vector>

const int modul = (int) 1e9 + 7;

int powermod(int a, int b, int n=modul) {
    if (b == 0) return 1;
    long long tmp = powermod(a, b / 2, n);
    if (b % 2 == 0) return (tmp * tmp) % n;
    return (((tmp * tmp) % n) * a) % n;
}

int getRoot(int parents[], int i) {
    while (parents[i] != i)
        i = parents[i];
    return i;
}

/**
 * @brief this problem is a modified version of the how-many-connected-components-
 * in-a-graph problem. In the original problem, we need to calculate the nb of
 * connected components, in this case we need to compute the nb of vertices in
 * each component. Though demands seem different, it in fact just requires a
 * small twist in the original algorithm. Each time we change root of a node
 * (farthest ancestor), we accumulate all into the root and left un-root node
 * Zero. That way at the end, every strictly positive element is the nb of 
 * vertices in a components (and the nb of components = nb of strictly positive
 * elements). Done
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv) {
    int n, k;
    std::cin >> n >> k;
    
    int roots[n], accums[n];
    for (int i = 0; i < n; i++) {
        roots[i] = i;
        accums[i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, cl;
        std::cin >> u >> v >> cl;
        u--, v--;
        if (cl == 0) {
            int x = getRoot(roots, u);
            int y = getRoot(roots, v);
            if (x != y) {
                roots[x] = y;
                accums[y] += accums[x];
                accums[x] = 0;
            }
        }
    }

    std::vector<int> counts;
    for (int i = 0; i < n; i++) 
        if (accums[i] > 0) counts.push_back(accums[i]);

    long long result = 0;
    for (int j = 0; j < counts.size(); j++)
        result = (result + powermod(counts[j], k)) % modul;
    result = powermod(n, k) + modul - result;
    std::cout << result % modul << std::endl;
}