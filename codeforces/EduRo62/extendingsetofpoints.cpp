#include <iostream>
#include <unordered_set>

typedef std::pair<int, int> P;

const ulong size = (ulong) (3 * 1e5);
int tab[size * size] = {0};
std::unordered_set<ulong> rows[size];
std::unordered_set<ulong> cols[size];

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    int extends = 0;
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        int idx = u * size + v;
        if (tab[idx] == 0) {
            for (auto& e: rows[u]) 
                for (auto& f: cols[v]) {
                    int ec, fr;
                    ec = e % size;
                    fr = f / size;
                    if (tab[fr * size + ec] == 0) {
                        extends ++;
                    }
                }
            tab[idx] = 1;
            rows[u].insert(idx);
            cols[v].insert(idx);
        }
        else {
            rows[u].erase(idx);
            cols[u].erase(idx);
            for (auto& e: rows[u])
                for (auto& f: cols[v]) {
                    int ec, fr;
                    ec = e % size;
                    fr = f / size;
                    if (tab[fr * size + ec] == 0) {
                        extends --;
                    }
                }
            tab[idx] = 0;
        }
        std::cout << extends << std::endl;
    }
}