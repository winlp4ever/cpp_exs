#pragma once

#include <iostream>

class Point {
public:
    double x, y;
    
    Point(double x, double y);
    Point(const Point& p);
    ~Point();
    Point& operator=(const Point& p);

    friend std::ostream& operator<<(std::ostream& in, const Point& p);
    friend double dist(const Point& u, const Point& v);
};