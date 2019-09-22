#pragma once

#include <algorithm>
#include <cstdlib>

using namespace std;

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    
    SimpleVector(const SimpleVector& rhs)
    : data_begin(new T[rhs.capacity])
    , capacity(rhs.capacity)
    , size(rhs.size)
    {
        copy(rhs.begin(), rhs.end(), begin());
    };
    
    explicit SimpleVector(size_t size) {
        data_begin = new T[size];
        capacity = size;
        this->size = size;
    }
    
    ~SimpleVector() {
        delete[] data_begin;
    }
    
    void operator=(const SimpleVector<T>& rhs) {
        if (capacity >= rhs.size) {
            copy(rhs.begin(), rhs.end(), begin());
            size = rhs.Size();
        } else {
            SimpleVector<T> temp(rhs);
            swap(temp.data_begin, data_begin);
            swap(temp.size, size);
            swap(temp.capacity, capacity);
        }
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
    
    const T* begin() const {
        return data_begin;
    }
    
    const T* end() const {
        return data_begin + size;
    }
    
    size_t Size() const {
        return size;
    }
    
    size_t Capacity() const {
        return capacity;
    }
    
    void PushBack(const T& value) {
        if (Size() == 0) {
            data_begin = new T[++capacity];
        } else if (Size() == Capacity()) {
            capacity *= 2;
            T* new_data = new T[Capacity()];
            for (size_t i = 0; i < Size(); ++i) {
                new_data[i] = data_begin[i];
            }
            
            delete[] data_begin;
            data_begin = new_data;
        }
        
        data_begin[size++] = value;
    }
    
private:
    T* data_begin = nullptr;
    size_t capacity = 0;
    size_t size = 0;
};
