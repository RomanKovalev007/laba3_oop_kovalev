#include "array.h"


Array::Array() : data(nullptr), capacity(0), size(0) {}

Array::Array(size_t capacity) : capacity(capacity), size(0) {
    data = new Figure*[capacity]();

}


Array::Array(const Array& other) : capacity(other.capacity), size(other.size) {
    data = new Figure*[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i]->clone();
    }
}

Array::Array(Array&& other) noexcept 
    : data(other.data), capacity(other.capacity), size(other.size) {
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

Array::~Array() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    size = 0;
    delete[] data;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        size = 0;
        delete[] data;
        
        capacity = other.capacity;
        size = other.size;
        data = new Figure*[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i]->clone();
        }
    }
    return *this;
}


Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        size = 0;
        delete[] data;
        
        data = other.data;
        capacity = other.capacity;
        size = other.size;
        
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}


void Array::resize(size_t newCapacity) {
    Figure** newData = new Figure*[newCapacity]();
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}


void Array::push(Figure* figure) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size] = figure;
    size++;
}


void Array::remove(size_t idx) {
    if (idx >= size) {
        throw std::out_of_range("index out of range");
    }
    delete data[idx];
    for (size_t i = idx; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
    data[size] = nullptr;
}


Figure*& Array::operator[](size_t idx) {
    if (idx >= size) {
        throw std::out_of_range("index out of range");
    }
    return data[idx];
}


const Figure* Array::operator[](size_t idx) const {
    if (idx >= size) {
        throw std::out_of_range("index out of range");
    }
    return data[idx];
}


size_t Array::getSize() const {
    return size;
}


size_t Array::getCapacity() const {
    return capacity;
}


bool Array::isEmpty() const {
    return size == 0;
}




double Array::totalArea() const {
    double res = 0.0;
    for (size_t i = 0; i < size; ++i) {
        if (data[i]) {
            res += static_cast<double>(*data[i]);
        }
    }
    return res;
}