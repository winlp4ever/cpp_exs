#include <iostream>
#include <random>
#include <time.h>

void swap(int a[], const int &i, const int &j) {
    if (i == j) return;
    a[i] += a[j];
    a[j] = a[i] - a[j];
    a[i] -= a[j];
}

int partition(int a[], const int &lo, const int& hi) {
    int p = a[hi];
    int m = lo;
    for (int i = lo; i < hi; i++) {
        if (a[i] < p) 
            swap(a, i, m++);
    }
    swap(a, m, hi);
    return m;
}

void quicksort(int a[], const int &lo, const int& hi) {
    if (hi < lo+1) return;
    int m = partition(a, lo, hi);
    quicksort(a, lo, m-1);
    quicksort(a, m+1, hi);
}

void sort(int a[], const int& n) {
    quicksort(a, 0, n-1);
}

void printArr(int a[], const int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
    std::cout << "]" << std::endl;
}

const int module = (int) 1e4;

int main(int argc, char** argv) {
    int n = atoi(argv[1]);
    int a[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) a[i] = rand() % module;
    printArr(a, n);
    sort(a, n);
    printArr(a, n);
    return 0;
}