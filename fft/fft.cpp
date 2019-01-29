#include <iostream>
#include <algorithm>
#include <exception>
#include <complex>
#include <time.h>
#include <random>
#include <iomanip>

const double pi = std::acos(-1);

/** Rearrange the array so that elements with even index locate in the first half and
 * one with odd index in the second half
*/
void half_permute(std::complex<double>* a, const int& n) {
    std::complex<double>* b = new std::complex<double>[n / 2];
    for (int i = 0; i < n; i += 2) {
        a[i / 2] = a[i];
        b[i / 2] = a[i + 1];
    }
    for (int i = 0; i < n / 2; i++) {
        a[i + n / 2] = b[i];
    }

    delete[] b;
}

void fft(std::complex<double>* v, const int& N) {
    // cooley-tukey algorithm

    for (int t = N; t > 2; t /= 2) {
        for (int k = 0; k < N / t; k++) {
            half_permute(v + k * t, t);
        }
    }

    for (int t = 2; t <= N; t *= 2) {
        for (int u = 0; u < N / t; u++) {
            for (int i = 0; i < t / 2; i++) {
                std::complex<double> expo = std::exp(std::complex<double>(0., -2. * pi * i / (double) t));
                v[u * t + i] += expo * v[u * t + i + t / 2];
                v[u * t + i + t / 2] = v[u * t + i] - 2. * expo * v[u * t + i + t / 2];
            }
        }
    }
}

/** 
 * Recursive version of cooley tukey algorithm
 */
void fft_recursive(std::complex<double>* v, const int& N) {
    if (N == 1)
        return;
    half_permute(v, N);
    fft_recursive(v, N / 2);
    fft_recursive(v + N / 2, N / 2);
    for (int k = 0; k < N / 2; k++) {
        std::complex<double> expo = std::exp(std::complex<double>(0, -2. * pi * k / (double) N));
        v[k] += expo * v[k + N / 2];
        v[k + N / 2] = v[k] - 2. * expo * v[k + N / 2];
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    int N = 1 << atoi(argv[1]); // read int from command line arg
    long begin = time(NULL);
    std::complex<double>* u = new std::complex<double>[N];
    for (int i = 0; i < N; i++) {
        u[i] = std::complex<double>(rand() / (double) RAND_MAX * 100 - 50, rand() / (double) RAND_MAX * 100 - 50);
    }

    auto print = [](std::complex<double>* u, const int& N) {
        for (int i = 0; i < N; i++) {
            std::cout << std::fixed;
            std::cout << std::setprecision(2) << u[i] << " ";
        }
        std::cout << std::endl;
    };
    std::cout << "Original sequence:\n" << std::endl;
    print(u, N);

    std::complex<double>* v(u);
    fft(u, N);
    fft_recursive(v, N);
    std::cout << "Fourier transform:\n" << std::endl;
    print(u, N);
    print(v, N);
    return 0;
}