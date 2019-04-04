#include <iostream>
#include <cmath>

long long power(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    long long u = power(n, k / 2);
    if (k % 2 == 0) return u * u;
    return u * u * n;
}

long long max(long long a, long long b) {
    return (a > b)? a: b;
}

long long max_prod(int n, int k) {
    if (k == 0) return n;
    int div = n / (int) power(10, k);
    if (div == 0) return 0;
    return max((div - 1) * power(9, k), div * max_prod(n % power(10, k), k - 1));
}

main(int argc, char** argv) {
    int n;
    std::cin >> n;
    int k = (int) std::log10(n);
    long long u = max_prod(n, k);
    std::cout << max(u, power(9, k)) << std::endl;
}