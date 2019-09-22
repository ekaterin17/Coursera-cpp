#include <algorithm>
#include <cstdlib>

using namespace std;

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    
    explicit SimpleVector(size_t size) {
        data_begin = new T[size];
        capacity = size;
        this->size = size;
    }
    
    ~SimpleVector() {
        delete[] data_begin;
    }
    
    T& operator[](size_t index) {
        return data_begin[index];
    }
    
    T* begin() {
        return data_begin;
    }
    
    T* end() {
        return data_begin + size;
    }
    
    size_t Size() const {
        return size;
    }
    
    size_t Capacity() const {
        return capacity;
    }
    
    void PushBack(T value) {
        if (Size() == 0) {
            data_begin = new T[++capacity];
        } else if (Size() == Capacity()) {
            capacity *= 2;
            T* new_data = new T[Capacity()];
            move(begin(), end(), new_data);
            
            delete[] data_begin;
            data_begin = new_data;
        }
        
        data_begin[size++] = move(value);
    }
    
private:
    T* data_begin = nullptr;
    size_t capacity = 0;
    size_t size = 0;
};
