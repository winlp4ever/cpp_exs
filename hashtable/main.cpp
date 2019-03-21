#include <iostream>
#include <unordered_map>
#include <string>
#include <typeinfo>

int main(int argc, char** argv) {
    std::unordered_map<std::string, int> hm = {{"red", 0}, {"blue", 1}}; // declare a hash map
    for (auto &u: hm) std::cout << "Key: " << u.first << " - Value: " << u.second << std::endl;
    hm["blue"] = 5; // modify value of a key

    // add new keys to hash map
    hm["orange"] = 3;
    hm["green"] = 4;
    for (auto& u: hm) std::cout << u.first << " - " << u.second << std::endl;

    auto find_result = hm.find("yellow"); // check if a key exists
    std::cout << "find yellow: " << ((find_result == hm.end())? "not found!": "found!") << std::endl;

    int u;
    std::cout << (typeid(u) == typeid(int)) << std::endl; // check type of a value
}