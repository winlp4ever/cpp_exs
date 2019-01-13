#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

class A {
public:
    int i;
    A(int i) {this->i = i;}
};

class Printer {
public:
    void operator() (A a) { cout << a.i << " ";}
    // this is needed when using `for_each`
};

bool compare(A a, A b) {return (a.i < b.i);}

template<int i, int d> class Prime {
public:
    enum { result = (i % d) && Prime<i, d - 1>::result };
};

template<int i> class Prime<i, 1> {
public:
    enum { result = true };
};

template<int i> class isPrime {
public:
    enum { result = Prime<i, i - 1>::result };
};

template<> class isPrime<1> {
public:
    enum { result = false };
};

int main(int argc, char* argv[]) {
    Printer p;
    vector<A> l;
    l.push_back(A(10));
    l.push_back(A(30));
    l.push_back(A(20));
    l.push_back(A(40));
    sort(l.begin(), l.end(), compare);

    for_each(l.begin(), l.end(), p);

    cout << isPrime<5>::result << endl;
    cout << isPrime<28>::result << endl;
    cout << isPrime<1>::result << endl;
    return 0;
}