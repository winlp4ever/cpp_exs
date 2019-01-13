#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> * arr;
public:
    MaxHeap() { arr = new vector<int>(); }
    ~MaxHeap() { delete arr; }

    int& operator[](const int& index) {
        return (*arr)[index];
    } 

    int operator[](const int& index) const {
        return (*arr)[index];
    }

    int pollBack() {
        int last = arr->back();
        arr->pop_back();
        return last;
    }

    void swap(const int& i, const int& j) {
        if (i == j) return;
        (*arr)[i] += (*arr)[j];
        (*arr)[j] = (*arr)[i] - (*arr)[j];
        (*arr)[i] -= (*arr)[j];
    }

    void insert(const int& a) {
        arr->push_back(a);
        int idx = arr->size() - 1;
        while (idx > 0) {
            if (a > (*this)[(idx - 1) / 2]) {
                this->swap(idx, (idx - 1) / 2);
                idx = (idx - 1) / 2;
            }
            else
                break;            
        }
    }

    bool isEmpty() const noexcept{
        return arr->size() == 0;
    }

    int size() const noexcept{
        return arr->size();
    }

    int extract() {
        if (isEmpty())
            throw "The heap is empty, nothing to extract!";

        swap(0, size() - 1);
        int last = pollBack();
        int idx = 0;
        int id = 1;
        while (id < size()) {
            if (id + 1 < size() && (*arr)[id + 1] > (*arr)[id])
                id ++;
            if ((*arr)[idx] < (*arr)[id]) {
                swap(idx, id);
                idx = id;
                id = 2 * idx + 1;
            }
            else 
                break;
        }
        return last;
    }

    friend ostream& operator<<(ostream& stream, const MaxHeap& heap);
};

// friend method, should be declared within class block, but defined outside (without keyword friend)
ostream& operator<<(ostream& stream, const MaxHeap& heap) {
    if (heap.isEmpty())
        stream << "EMPTY";
    else {
        int idx = 0;
        while (idx < heap.size()) {
            for (int i = idx; i < 2 * idx + 1; i++) {
                if (i < heap.size())
                    stream << heap[i];
                else 
                    stream << "NULL";
                if (i < 2 * idx) 
                    stream << " ";
            }
            idx = 2 * idx + 1;
            if (idx < heap.size())
                stream << "\n";
        }
    }
    return stream;
    
}

int main(int argc, char* argv[]) {
    MaxHeap heap;
    heap.insert(5);
    heap.insert(17);
    heap.insert(23);
    heap.insert(16);
    heap.insert(9);
    heap.extract();
    heap.extract();
    cout << heap << endl;
    return 0;
}