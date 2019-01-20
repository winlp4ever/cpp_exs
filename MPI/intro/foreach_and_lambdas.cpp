// In this file, view examples on std::for_each and lambdas functions in c++
#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include <set>

struct badge {
    int id, age;
    std::string name;

    badge(int i, int a, std::string n): id(i), age(a), name(n) {};
    badge(const badge& b): id(b.id), age(b.id), name(b.name) {};
    ~badge() {};

    badge& operator=(const badge& b) {
        if (this == &b)
            return *this;
        id = b.id;
        age = b.age;
        name = b.name;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &in, const badge& b) {
        in << "id: " << b.id << " age: " << b.age << " name: " << b.name;
        return in;
    }
};

int main(int argc, char** argv) {
    badge ls_students[] {badge(0, 23, "Quang"), badge(2, 24, "Dang"), badge(1, 24, "Dung")};
    badge* ls(ls_students);

    // from c++11, a new feature is implemented - the lambda functions, see how similar it is compared to lambdas in python
    // format is [](args) {...}
    // if you want to define a local func (func in func), you can write
    // auto f = [](args) {...};
    std::sort(ls, ls + 3, [](const badge &u, const badge &v) {
        return u.id < v.id;
    });
    std::for_each(ls, ls + 3, [](const badge& b) {
        std::cout << b << std::endl;
    });
}