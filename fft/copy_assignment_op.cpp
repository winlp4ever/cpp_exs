#include <iostream>
#include <iterator>

template<class T> class My_Array{
    T* array;
    int count;
public:
    My_Array(const int& size): count(size) {
        array = new T[count];
    }

    My_Array(const My_Array& other) {
        if (this != &other) { // protect against invalid self-assignment

            // 2: allocate new memory and copy the elements
            array = new T[other.count];
            std::copy(other.array, other.array + other.count, array);

            count = other.count;
        }
    }

    My_Array& operator=(const My_Array& other)
    {
        if (this != &other) { // protect against invalid self-assignment
            // 1: deallocate old memory
            delete[] array;

            // 2: allocate new memory and copy the elements
            T* new_array = new T[other.count];
            std::copy(other.array, other.array + other.count, new_array);

            // 3: assign the new memory to the object
            array = new_array;
            count = other.count;
        }
        // by convention, always return *this
        return *this;
    }

    T& operator[](const uint& i) {
        if (i >= count)
            throw std::runtime_error("invalid index!");
        return array[i];
    } 

    T operator[](const uint& i) const {
        if (i >= count)
            throw std::runtime_error("invalid index!");
        return array[i];
    }

    friend std::ostream& operator<<(std::ostream& in, const My_Array& arr) {
        std::copy(arr.array, arr.array + arr.count, std::ostream_iterator<T>(std::cout, " "));
    }
    // ...
};

int main(int argc, char** argv) {
    int* u = new int[5];
    My_Array<double> me(5);
    std::cout << u[7] <<std::endl;
}