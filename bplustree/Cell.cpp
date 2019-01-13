#include "Cell.h"
#include "Zone.h"

#include <iostream>

using namespace std;

Cell::Cell(int a) {
    value = a;
    left = NULL;
    right = NULL;
}

Cell::Cell(int a, Zone *l, Zone *r) {
    value = a;
    left = l;
    right = r;
}

Cell::~Cell() {
    delete left, right;
}

int Cell::val() const {
    return value;
}

Zone*& Cell::getL() {
    return left;
}

Zone*& Cell::getR() {
    return right;
}