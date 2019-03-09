#include <iostream>
#include <cmath>
#include <exception>
#include <typeinfo>
#include <string>
#include <cxxabi.h>
#include <sstream>

#define BOLD    "\e[1m"
#define NBOLD   "\e[0m"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m" 

#ifndef ASSERT
#define ASSERT( expression ) \
    if (expression != true) { \
        std::cerr << "\n" << BOLD << BLACK << __FILE__ << ":" << __LINE__ << RESET; \
        std::cerr << RED << " assertion error: " << RESET; \
        std::cerr << "\'" << #expression << "\':\n"; \
        throw std::runtime_error(""); \
    }
#endif


int tria_area(const double &a, const double &b, const double &c) {
    ASSERT( (a + b > c && b + c > a && a + c > b) );
    double p = (a + b + c) / 2.f;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


int main(int argc, char** argv) {
    double a, b, c;
    ASSERT( argc == 4 );
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
    std::cout << "triangle area: " << tria_area(a, b, c) << std::endl;
}