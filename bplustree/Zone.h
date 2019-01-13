#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Cell.h"

using namespace std;

class Cell;

class Zone {
private:
    bool isLeaf;
    int cap = 4;
    vector<Cell*> elements;
public:
    Zone();
    Zone(bool isL);
    Zone(vector<Cell*> eles);
    Zone(vector<Cell*> eles, bool isL);
    ~Zone();
    Cell* divides();
    bool insert(Cell* c); //return false if already exist, else true
    Zone* search(const int& a);
    int size() const;
    int getCap() const;
    bool is_leaf() const;
    bool exceeds();

    Cell* insert_plus(const int& a);
    string toString();

    vector<Zone*> descs_of_zone();
};