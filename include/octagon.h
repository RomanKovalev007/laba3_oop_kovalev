#pragma once

#include "figure.h"

class Octagon : public Figure {
    Point points[8];
public:
    Octagon();
    Octagon(const Point points[8]);

    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept;

    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;
    bool operator==(const Octagon& other) const;
    
    Point gcenter() const override;
    double area() const override;
    
    void print(std::ostream& out) const override;
    void read(std::istream& in) override;

    Octagon *clone() const override;
private:
    void sort();
    bool isOctagon();
};
