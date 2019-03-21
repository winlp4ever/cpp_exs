#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
std::ostream& operator<<(std::ostream& in, const std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) in << v[i] << " ";
    return in;
}

int main (int argc, char** argv) {
    std::vector<int> v = {0, 9, 8, 12, 5, 7, 3, 19, 8, 2};
    std::make_heap (v.begin(), v.end()); // make heap from a vector
    std::cout << v << std::endl;

    std::cout << v.front() << std::endl; // retrieve largest ele

    v.push_back(6);
    std::push_heap(v.begin(), v.end()); // how to insert an element to the heap
    std::cout << v << std::endl;

    std::pop_heap(v.begin(), v.end()); // how to poll first (largest ele)
    v.pop_back();
    std::cout << v << std::endl;

}