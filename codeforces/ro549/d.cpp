#include <iostream>
#include <cmath>

typedef std::pair<int, int> P;

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a > b) return gcd(a % b, b);
    return gcd(a, b % a);
}

P solve(int n, int k, int u) {
    int w, v, h;
    h = gcd(k, u);
    w = u / h;
    v = k / h;
    int max_gcd = -1;
    for (int j = 0; j < n; j++) {
        int tmp = gcd(w + j * v, n);
        int tmp_ = gcd(k - w + j * v, n);
        if (max_gcd < tmp) max_gcd = tmp;
        if (max_gcd < tmp_) max_gcd = tmp_;
    }
    return P(v * n / max_gcd, v * n);
}


int main(int argc, char** argv) {
    int n, k;
    std::cin >> n >> k;
    int a, b;
    std::cin >> a >> b;
    int u, r;
    u = (b - a) % k;
    r = (b + a) % k;
    if (u < 0) u += k;
    if (r >= k) r -= k;
    P solu, solr;
    solu = solve(n, k, u);
    solr = solve(n, k, r);
    int min_l, max_l;
    min_l = std::min(solu.first,solr.second);
    max_l = std::max(solu.second, solr.second);
    std::cout << min_l << " " << max_l << std::endl;
}