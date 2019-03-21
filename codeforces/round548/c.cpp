#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <unordered_set>

using namespace std;

const int modul = (int) 1e9 + 7;

int powermod(int a, int b, int n=modul) {
    if (b == 0) return 1;
    long long tmp = powermod(a, b / 2, n);
    if (b % 2 == 0) return (tmp * tmp) % n;
    return (((tmp * tmp) % n) * a) % n;
}

struct ver {
    int idx, par, h;
    ver(int i, int p): idx(i), par(p), h(0) {};
    ~ver() {};

    int find_par(vector<ver> vertices) const {
        if (idx == par) return idx;
        else 
            return vertices[par].find_par(vertices);
    }

    void join(ver& v, vector<ver> &vertices) {
        ver& p = vertices[find_par(vertices)];
        ver& pv = vertices[v.find_par(vertices)];
        if (p.h > pv.h) {
            p.par = pv.par;
            p.h++;
        }
        else {
            pv.par = p.par;
            pv.h++;
        }
    };
    
    bool same_comp(const ver& v, vector<ver> vertices) {
        return find_par(vertices) == v.find_par(vertices);
    }

    friend std::ostream& operator<<(std::ostream& in, const ver& v) {
        in << v.idx + 1 << " " << v.par + 1 << " " << v.h;
        return in;
    }
};

int main(int argc, char** argv) {
    int n, k;
    std::cin >> n >> k;
    std::vector<ver> vertices;
    for (int i = 0; i < n; i++) vertices.push_back(ver(i, i));
    int n_components = 0;
    for (int i = 0; i < n - 1; i++) {
        int x, y, c;
        std::cin >> x >> y >> c;
        if (c == 0) {
            vertices[x - 1].join(vertices[y - 1], vertices);
            n_components++;
        }
    }
    n_components = n - n_components;
    std::vector<int> reps;
    std::vector<int> counts(n_components);
    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        bool check = true;
        for (int j = 0; j < reps.size(); j++)
            if (it->same_comp(vertices[reps[j]], vertices)) {
                counts[j]++;
                check = false;
                break;
            }
        if (check) {
            reps.push_back(it->idx);
            counts[reps.size() - 1]++;
        }
    }
    
    long long result = 0;
    for (int j = 0; j < counts.size(); j++)
        result = (result + powermod(counts[j], k)) % modul;
        //result += (long long) std::pow(counts[j], k);
    result = powermod(n, k) + modul - result;
    std::cout << result % modul << std::endl;
}