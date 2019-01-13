#pragma once
#ifndef CAR_HPP
#define CAR_HPP
#include <string>

class car {
    private:
        std::string user;
        int price;

    public:
        car(std::string s, int p);
        virtual ~car();
        virtual std::string toString() const;
};
#endif