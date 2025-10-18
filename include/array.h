#pragma once

#include <iostream>
#include <stdexcept>
#include "../include/figure.h"

class Array {
private:
    Figure** data;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);

public:
    Array();
    Array(size_t capacity);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    Figure*& operator[](size_t idx);
    const Figure* operator[](size_t idx) const;

    void push(Figure* figure);
    void remove(size_t idx);

    size_t getSize() const;
    size_t getCapacity() const;
    bool isEmpty() const;

    double totalArea() const;
};
