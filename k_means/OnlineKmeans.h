#pragma once

#include <iostream>
#include <vector>
#include "Point.h"
#include "Stream.h"

class OnlineKmeans {
public:
    OnlineKmeans(int K, Stream* s);
    OnlineKmeans(int K, Stream* s, std::vector<Point*> ps);
    ~OnlineKmeans();
    void update();
    friend std::ostream& operator<<(std::ostream& in, const OnlineKmeans& ins);
private:
    int clusters;
    std::vector<Point*> centroids;
    Stream* stream;
};