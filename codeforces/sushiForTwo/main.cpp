#include <iostream>


int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    int max_len(0), old_len(0), len(0), state(0);
    for (int i = 0; i < n; i++) {
        int sushi;
        std::cin >> sushi;
        if (sushi != state) {
            if (max_len < std::min(old_len, len))
                max_len = std::min(old_len, len);
            old_len = len;
            len = 1;
            state = sushi;
        }
        else {
            len++;
        }
    }
    if (max_len < std::min(old_len, len))
        max_len = std::min(old_len, len);
    std::cout << (2 * max_len) << std::endl;
    return 0;
}