#include <iostream>
#include <assert.h>


struct ResizableArray {
    int* a;
    int cap;
    int length;
    ResizableArray(int c): cap(c), length(0) {
        assert(c > 0 && "capa must be strictly positive!");
        a = new int[cap];
    }

    ~ResizableArray() {
        delete [] a;
    }

    int& operator[](const int &i) {
        return a[i];
    }

    int operator[](const int &i) const {
        return a[i];
    }

    void doubleSize() {
        int *arr = new int[2 * cap];
        std::copy(a, a + length, arr);
        delete a;
        a = arr;
        cap *= 2;
    }

    void push(int u) {
        if (length == cap) doubleSize();
        a[length++] = u;
    }

    void push(int u[], int l) {
        for (int i = 0; i < l; i++) push(u[i]);
    }

    void swap(const int &i, const int& j) {
        if (i == j) return;
        a[i] += a[j];
        a[j] = a[i] - a[j];
        a[i] -= a[j];
    }

    friend std::ostream& operator<<(std::ostream& in, const ResizableArray &arr) {
        in << "[ ";
        for (int i = 0; i < arr.length; i++) in << arr[i] << " ";
        in << "]";
        return in;
    }
};


void testResiArr() {
    ResizableArray arr(3);
    arr.push(1);
    arr.push(4);
    arr.push(5);
    arr.push(2);
    std::cout << arr << std::endl;
    std::cout << arr.cap << std::endl;
    std::cout << arr.length << std::endl;
}


void heappush(ResizableArray &arr, int u) {
    arr.push(u);
    int l = arr.length - 1;
    while (l >= 0) {
        int l_ = l / 2;
        if (arr[l_] < arr[l]) {
            arr.swap(l_, l);
            l = l_;
        }
        else break;
    }
}

void heappop(ResizableArray &arr) {
    assert(arr.length > 0 && "cannot pop an empty arr!");
    arr.swap(0, --arr.length);
    int l = 0;
    while (true) {
        int l_ = 2*l + 1;
        if (l_ >= arr.length) break;
        if (l_ + 1 < arr.length && arr[l_ + 1] > arr[l_]) l_++;
        if (arr[l_] > arr[l]) {
            arr.swap(l, l_);
            l = l_;
        }
        else break;
    }
}

ResizableArray heapify(ResizableArray &arr) {
    ResizableArray new_arr(arr.cap);
    for (int i = 0; i < arr.length; i++) heappush(new_arr, arr[i]);
    return new_arr;
}

void heapsort(ResizableArray &arr) {
    int n = arr.length;
    while(arr.length > 0) heappop(arr);
    arr.length = n;
}

void printArr(int a[], const int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
    std::cout << "]" << std::endl;
}

int main(int argc, char** argv) {
    //testResiArr();
    ResizableArray a(1);
    int l = atoi(argv[1]);
    int init[l];
    srand(time(NULL));
    for (int i = 0; i < l; i++) init[i] = rand() % 1000;
    a.push(init, l);
    printArr(a.a, a.length);
    ResizableArray b = heapify(a);
    printArr(b.a, b.length);
    int n = b.length;
    heapsort(b);
    printArr(b.a, b.length);
}