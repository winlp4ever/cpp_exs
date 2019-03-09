#include <iostream>
#include "Stream.h"
#include "Point.h"

Stream::~Stream() {};

Point Stream::next_item() {
    throw std::runtime_error("unimplemented!");
};

bool Stream::end() {
    throw std::runtime_error("unimplemented!");
}