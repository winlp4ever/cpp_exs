#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <stdlib.h>
#include "KmeansTest.h"
#include "Point.h"

KmeansTest::KmeansTest(int K): clusters(K) {
    gen.seed(time(NULL));
    for (int i = 0; i < K; i++) {
        centroids.push_back(new Point((double) rand()/ RAND_MAX, 
                                    (double) rand() / RAND_MAX));
    }
};

KmeansTest::~KmeansTest() {
    for (auto it = centroids.begin(); it != centroids.end(); it++) {
        delete *it;
    }
    centroids.clear();
}

Point KmeansTest::next_item() {
    count++;
    std::uniform_int_distribution<> U(0, clusters - 1);
    int c = U(gen);
    std::normal_distribution<double> Nx(centroids[c]->x, 0.001);
    std::normal_distribution<double> Ny(centroids[c]->y, 0.001);
    return Point(Nx(gen), Ny(gen));
}

/**
 * @brief check whether the stream is ended
 * 
 * @return true 
 * @return false 
 */
bool KmeansTest::end() {
    return false;
}

std::ostream& operator<<(std::ostream& in, const KmeansTest& t) {
    in << "test centroids:" << std::endl;
    for (auto it = t.centroids.begin(); it != t.centroids.end(); it++) {
        in << **it << std::endl;
    }
    return in;
};
