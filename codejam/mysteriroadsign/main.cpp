#include <iostream>
#include <vector>

typedef std::pair<int, int> pair;

struct Tab {
    int begin, end;
    pair e1, e2;  
    Tab(int i, pair e): begin(i), e1(e) {};
    ~Tab() {};
};

inline bool operator==(const pair &a, const pair &b) {
    return (a.first == b.first) && (a.second == b.second);
}

inline bool half_equals(const pair &a, const pair &b) {
    return (a != b) && ((a.first == b.first) || (a.second == b.second));
}

pair solution(const int& s, const std::vector<pair> &vec) {
    for (int i = 0; i < s; ++i) {
        
    }
}

int main(int argc, char** argv) {
    Tab tab(0, pair(1, 1));
    std::cout << tab.e1.first << std::endl;
}