#include <iostream>
#include "car.hpp"
#include "mer.h"
using namespace std;

int& ret(int* a, const int& i) {
    return *(a + i);
}

class vehicle {
    public:
    vehicle() {};
    virtual ~vehicle() {};
    virtual void toString() {
        std::cout << "this is a vehicle!" << std::endl;
    }
};

class camion: public vehicle {
    public:
    ~camion() {};
    void toString() {
        std::cout << "this is a camion" << std:: endl;
    }
};

int main(int argc, char** argv) {
    car u("tyty", 1024);
    cout << u.toString() << endl;

    car* m = new mer("me", 100);
    cout << m->toString() << endl;

    delete m;

    vehicle* v = new camion;
    v->toString();
    
    delete v; // ALWAYS remember to DELETE POINTER OBJS
    return 0;
}