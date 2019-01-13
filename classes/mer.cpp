#include "mer.h"
#include "car.hpp"
#include <iostream>

using namespace std;

string mer::toString() const {
    return car::toString() + " mark mercedes";
}

// call super class initializer
mer::mer(string s, int p): car::car(s, p) {
    this->mark = "mercedes";
}

mer::~mer() {};

