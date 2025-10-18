#pragma once

#include "figure.h"

class Triangle : public Figure {
    Point points[3];
public:
    Triangle();
    Triangle(const Point points[3]);

    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    bool operator==(const Triangle& other) const;
    
    Point gcenter() const override;
    double area() const override;
    
    void print(std::ostream& out) const override;
    void read(std::istream& in) override;

    Triangle *clone() const override;
private:
    void sort();
    bool isTriangle();
};