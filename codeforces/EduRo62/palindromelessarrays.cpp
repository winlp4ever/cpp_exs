#include <iostream>
#include <vector>


const int modul = 998244353;


int main(int argc, char** args) {
    int n, k;
    std::cin >> n >> k;
    int arr[n];
    long long result = 1;
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    for (int i = 0; i < 2; i++) {
        if (result == 0) break;
        int memo = 0;
        int count = 0;
        long long mul = 1;
        for (int j = i; j < n; j += 2) {
            if (arr[j] != -1) {
                if (memo != 0) {
                    if (count == 0 && arr[j] == memo) {
                        result = 0;
                        break;
                    }
                    int sign = (count % 2 == 0)? -1: 1;
                    mul = (mul * (k - 1) - sign) / k;
                    if (arr[j] == memo) mul += sign;
                }
                result = (result * mul) % modul;
                memo = arr[j];
                mul = 1;
                count = 0;
            }

            else {
                count ++;
                if (j + 2 >= n && memo == 0) {
                    mul = (mul * k) % modul;
                }
                else mul = (mul * (k - 1)) % modul;
                if (j + 2 >= n) {
                    result = (result * mul) % modul;
                    mul = 1;
                }
            }
        }
    }
    std::cout << result << std::endl;
}