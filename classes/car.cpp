#include <iostream>
#include "car.hpp"

using namespace std;

car::car(string s, int p) {
    this->user = s;
    this->price = p;
};

car::~car() {};

string car::toString() const {
    return this->user + " price " + to_string(this->price);
}
