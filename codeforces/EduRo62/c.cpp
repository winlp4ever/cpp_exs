#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

typedef pair<int, int> p;
int main(int argc, char** argv) {
    int n, k;
    cin >> n >> k;
    vector<p> vec;
    vector<int> list_;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> v >> u;
        vec.push_back(p(u, v));
        list_.push_back(v);
    }
    sort(vec.begin(), vec.end(), [](p a, p b) {
        return a.first < b.first || (a.first == b.first && a.second >= b.second); 
    });
    sort(list_.rbegin(), list_.rend());
    int max = -1;
    for (int i = 0; i < n; i++) {
        int tmp = vec[i].second;
        int l = (n - i);
        l = (l > k)? k: l;
        auto id = find(list_.begin(), list_.end(), tmp);
        list_.erase(id);
        for (int j = 0; j < l - 1; j++) tmp += list_[j];
        tmp *= vec[i].first;
        max = (tmp > max) ? tmp: max;
    }
    std::cout << max << std::endl;
}