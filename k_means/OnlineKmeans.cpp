#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include "Point.h"
#include "OnlineKmeans.h"

OnlineKmeans::OnlineKmeans(int K, Stream* s): 
clusters(K), stream(s)
{
    for (int i = 0; i < K; i++) {
        centroids.push_back(new Point((double) rand()/ RAND_MAX, 
                                    (double) rand() / RAND_MAX));
    }
};

OnlineKmeans::OnlineKmeans(int K, Stream* s, std::vector<Point*> ps):
clusters(K), stream(s)
{
    centroids = ps;
};

OnlineKmeans::~OnlineKmeans() {
    for (auto it = centroids.begin(); it != centroids.end(); it++)
        delete *it;
    centroids.clear();
};

void OnlineKmeans::update() {
    Point u = stream->next_item();
    int t = stream->count;
    Point* c;
    double maxdist = -1.;
    double d;
    for (auto it = centroids.begin(); it != centroids.end(); it++) {
        if (maxdist < (d = dist(**it, u))) {
            maxdist = d;
            c = *it;
        }
    }
    c->x = c->x * (1. - 1. / t) + u.x * 1. / t;
    c->y = c->y * (1. - 1. / t) + u.y * 1. / t;
};

std::ostream& operator<<(std::ostream& in, const OnlineKmeans& ins) {
    in << "centroids: " << std::endl;
    for (auto it = ins.centroids.begin(); it != ins.centroids.end(); it++)
        in << **it << std::endl;
    return in;
};