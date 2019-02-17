#include <iostream>
#include <exception>
#include <string>

#include "UnimplementedError.h"


class Stream {
public:
    virtual int next_item() {
        throw UnimplementedError("Unimplemented!", __LINE__, __FILE__);
    };
    
    virtual bool end() noexcept(false) {
        throw UnimplementedError("Unimplemented!", __LINE__, __FILE__);
    }
};


class DataStream: public Stream {
public:
    DataStream(): Stream() {
        std::cout << "define something" << std::endl;
    };

    ~DataStream() {};

    int next_item() {
        std::cout << "now it's better" << std::endl;
    };
};


class FMSketch {
    static constexpr double phi = 0.77351;
    static const uint L = 12;
    Stream* stream;
    uint* storage;
    uint cap;
public:
    FMSketch(Stream* s, uint m): stream(s), cap(m) {
        storage = new uint[cap];
    };

    ~FMSketch() {}

    uint hash(uint x) {
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = (x >> 16) ^ x;
        return x;
    };

    /**
     * detect first nonzero bit in binary expression of an int
     */
    int rho(int u) {
        if (u == 0) return L;
        return (u % 2 == 0)? 1 + rho(u / 2): 0;
    }


    /**
     * @brief estim nb of distinct elements of a stream
     * 
     * @return int 
     */
    int estim() {
        uint8_t* bitmap = new uint8_t[L];
        while (!stream->end()) {
            bitmap[rho(stream->next_item())] = 1;
        }
        int u = 0;
        while(bitmap[u] == 1)
            u++;
        return (int) ((1 << u) / (double) phi);
    }

    
};


int main(int argc, char** argv) {
    DataStream stream;
    stream.next_item();
    try {
        stream.end();
    } catch (const UnimplementedError& e) {
        std::cout << e.what() << std::endl;
        std::cout << e._getErrorLineNumber() << std::endl;
        std::cout << e._getErrorFilename() << std::endl;
    }
    std::string str = "good";
    str += " company";
}
