#pragma once

#include <iostream>
#include "Zone.h"

class Zone;

class Cell {
private:
    int value;
    Zone *left, *right;
public:
    Cell(int a);
    Cell(int a, Zone *l, Zone *r);
    ~Cell();
    int val() const;
    Zone*& getL();
    Zone*& getR();
};