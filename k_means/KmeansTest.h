#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "Point.h"
#include "Stream.h"

class KmeansTest: public Stream {
private:
    std::default_random_engine gen;
    int clusters;
    std::vector<Point*> centroids;

public:
    KmeansTest(int K);
    ~KmeansTest();
    Point next_item();
    bool end();
    friend std::ostream& operator<<(std::ostream& in, const KmeansTest& t);
};