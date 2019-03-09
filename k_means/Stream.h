#pragma once

#include <iostream>
#include <exception>
#include "Point.h"

class Stream {
public:
    int count = 0;
    virtual ~Stream();

    virtual Point next_item(); 

    virtual bool end();
};