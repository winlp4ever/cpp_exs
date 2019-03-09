#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <typeinfo>
#include <typeindex>
#include <cxxabi.h>


namespace utilities {
    std::string type_name(const std::type_info& id) {
        return abi::__cxa_demangle(id.name(), 0, 0, 0);
    }
}

int main(int argc, char** argv) {
    std::string s = "test";
    std::cout << s[2] << std::endl;
    std::cout << typeid(int).name() << std::endl;
    std::cout << utilities::type_name(typeid(int)) << std::endl;

}