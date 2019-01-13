#include <iostream>
#include <random>
#include <string>

using namespace std;

// How to generate normally distributed numbers in C++



int main(int argc, char* argv[]) {
    default_random_engine generator;
    double mean = 5.;
    double stddev = 2.;
    normal_distribution<double> N(mean, stddev);

    const int nrolls = 100000;
    const int nstars = 100;
    int p[10] = {};
    for (int i=0; i<nrolls; ++i) {
        double number = N(generator);
        if ((number>=0.0)&&(number<10.0)) ++p[int(number)];
    }

  std::cout << "normal_distribution (5.0,2.0):" << std::endl;

  for (int i=0; i<10; ++i) {
    std::cout << i << "-" << (i+1) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

  return 0;
}