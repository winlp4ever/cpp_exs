#include "Zone.h"
#include "Cell.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

Zone::Zone() {
    isLeaf = false;
}

Zone::Zone(bool isL) {
    isLeaf = isL;
}

Zone::Zone(vector<Cell*> eles) {
    isLeaf = false;
    elements = eles;
}

Zone::Zone(vector<Cell*> eles, bool isL) {
    isLeaf = isL;
    elements = eles;
}
Zone::~Zone() {
    for (vector<Cell*>::iterator it = elements.begin(); it != elements.end(); it ++) {
        delete *it;
    }
}

Cell* Zone::divides() {
    int size = elements.size();
    vector<Cell*> u(elements.begin() + size / 2, elements.end());
    elements.erase(elements.begin() + size / 2, elements.end());
    int val = u[0]->val();
    if (!isLeaf) u.erase(u.begin());
    Cell* c = new Cell(val, new Zone(elements, isLeaf), new Zone(u, isLeaf));
    isLeaf = false;
    return c;
}

Zone* Zone::search(const int& a) {
    for (vector<Cell*>::const_iterator it = elements.begin(); it != elements.end(); it ++) {
        if ((*it)->val() > a) return (*it)->getL();
    }
    return (*(elements.end() - 1))->getR();
}

bool Zone::insert(Cell* c) {
    int idx = 0;
    for (vector<Cell*>::iterator it = elements.begin(); it != elements.end(); it ++) {
        if ((*it)->val() > c->val()) break;
        else if ((*it)->val() == c->val()) return false;    
        idx ++;
    }
    elements.insert(elements.begin() + idx, 1, c);

    if (idx > 0) (*(elements.begin() + idx - 1))->getR() = c->getL();

    if (idx < elements.end() - elements.begin() - 1) 
        (*(elements.begin() + idx + 1))->getL() = c->getR();

    return true;
}

int Zone::size() const {
    return elements.size();
}

int Zone::getCap() const {
    return cap;
}

bool Zone::is_leaf() const {
    return isLeaf;
}

bool Zone::exceeds() {
    return elements.size() > cap;
}

Cell* Zone::insert_plus(const int& a) {
    if (is_leaf()) insert(new Cell(a));
    else {
        Zone* z = search(a);
        Cell* c = z->insert_plus(a);
        if (c != NULL) insert(c);
    }
    if (exceeds())
        return divides();
    else
        return NULL;
}

string Zone::toString() {
    if (this == NULL) return "NULL";
    string s = "[ ";
    for (vector<Cell*>::const_iterator it = elements.begin(); it != elements.end(); it ++) {
        s += to_string((*it)->val()) + " ";
    }
    s += "]";
    return s;
}

vector<Zone*> Zone::descs_of_zone() {
    vector<Zone*> v;
    if (this == NULL) return v;
    for (vector<Cell*>::const_iterator it = elements.begin(); it != elements.end(); it ++) {
        Zone* c = (*it)->getL();
        if(c) v.push_back(c);
    }
    Zone* c = (*(elements.end() - 1))->getR();
    if (c) v.push_back(c);
    return v;
}