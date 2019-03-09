#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include "Point.h"
#include "KmeansTest.h"
#include "OnlineKmeans.h"

int main(int argc, char** argv) {
    srand(time(NULL));
    KmeansTest test(2);
    std::cout << test << std::endl;
    
    Point p0(0., 0.);
    Point p1(1., 1.);
    std::vector<Point*> v;
    v.push_back(&p0);
    v.push_back(&p1);
    OnlineKmeans kmeans(2, &test, v);

    std::cout << kmeans << std::endl;
    int niter = atoi(argv[1]);
    for (int i = 0; i < niter; i++) {
        kmeans.update();
    }
    std::cout << kmeans << std::endl;

}