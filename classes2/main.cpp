#include <iostream>

using namespace std;

class A {
private:
    int i;
public:
    A() {i = 0;}
    A(int i) {this->i = i;}
    virtual ~A() {};
    int getI() const {
        return i;
    }
};

class B: public A {
private:
    int j;
public:
    B() {j = 0;}
    B(int i): A(i) {j = 0;}

    ~B() {};
    int getJ() const {
        return j;
    }
};

int main(int argc, char* argv[]) {
    B b(2);
    cout << (b.getI()) << endl;

    return 0;
}