#include <iostream>
#include <math.h>
#include "Point.h"

Point::Point(double x_, double y_): x(x_), y(y_) {};

Point::Point(const Point& p) {
    x = p.x;
    y = p.y;
};

Point::~Point() {};

Point& Point::operator=(const Point& p) {
    if (&p == this)
        return *this;
    x = p.x;
    y = p.y;
    return *this;
};

std::ostream& operator<<(std::ostream& in, const Point& p) {
    in << "(" << p.x << ", " << p.y << ")";
    return in;
};

double dist(const Point& u, const Point& v) {
    double a = v.x - u.x;
    double b = v.y - u.y;
    return sqrt(a * a + b * b);
};