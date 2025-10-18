#pragma once

#include <iostream>
#include <cmath>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Point gcenter() const = 0;
    
    friend std::ostream& operator<<(std::ostream& out, const Figure& figure);
    friend std::istream& operator>>(std::istream& in, Figure& figure);
    
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    
    operator double() const;
    virtual double area() const = 0;
    virtual Figure *clone() const = 0;
    
};
