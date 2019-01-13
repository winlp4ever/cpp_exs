#pragma once

#include <iostream>
#include <string>
#include <set>

class Node {
private:
    std::string name;
    std::set<std::string> alias;
};