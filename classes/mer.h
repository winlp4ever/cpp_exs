#ifndef MER_H
#define MER_H

#include <string>
#include "car.hpp"

class mer: public car {
    private:
        std::string mark;
    public:
        mer(std::string s, int p);
        ~mer();
        std::string toString() const;
};

#endif