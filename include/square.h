#pragma once
#include "figure.h"

class Square : public Figure {
    Point points[4];
public:
    Square();
    Square(const Point points[4]);
    
    Square(const Square& other);
    Square(Square&& other) noexcept;

    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Square& other) const;

    Point gcenter() const override;
    double area() const override;

    void print(std::ostream& out) const override;
    void read(std::istream& in) override;

    Square *clone() const override;
private:
    void sort();
    bool isSquare();
};
