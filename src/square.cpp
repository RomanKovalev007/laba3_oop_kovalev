#include "../include/square.h"
#include <cmath>

Square::Square() {
    for (size_t i = 0; i < 4; ++i){
        points[i] = Point();
    }
}

Square::Square(const Point newPoints[4]) {
    for (size_t i = 0; i < 4; i ++){
        points[i] = newPoints[i]; 
    }
    sort();
    if (!isSquare()){
        throw std::invalid_argument("it is not a square");
    }
}

Square::Square(const Square& other){
    for (size_t i = 0; i < 4; ++i){
        points[i] = other.points[i];
    }
}

Square::Square(Square&& other) noexcept{
    for (size_t i = 0; i < 4; ++i){
        points[i] = std::move(other.points[i]);
    }
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        for (size_t i = 0; i < 4; ++i){
            points[i] = other.points[i];
        }
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < 4; ++i){
            points[i] = std::move(other.points[i]);
        }
    }
    return *this;
}

bool Square::operator==(const Square& other) const {
    for (size_t i = 0; i < 4; ++i){
        if (points[i].x != other.points[i].x || points[i].y != other.points[i].y){
            return false;
        };
    }
    return true;
}


Point Square::gcenter() const{
    double sx = 0, sy = 0;
    for (size_t i = 0; i < 4; ++i) {
        sx += points[i].x;
        sy += points[i].y;
    }
    return Point(sx / 4, sy / 4);
}

double Square::area() const {
    double sx = points[1].x - points[0].x;
    double sy = points[1].y - points[0].y;

    return sx*sx + sy*sy;
}

void Square::print(std::ostream& out) const {
    out << "square: ";
    for (size_t i = 0; i < 4; ++i) {
            out << "(" << points[i].x << ", " << points[i].y << ") ";
        }
}

void Square::read(std::istream& in) {
    for (size_t i = 0; i < 4; ++i) {
        in >> points[i].x >> points[i].y;
    }
    sort();
    if (!isSquare()){
        throw std::invalid_argument("it is not a square");
    }
}

Square *Square::clone() const{
    Square *newSquare = new Square();
    for (int i = 0; i < 4; ++i){
        newSquare->points[i] = this->points[i];
    }
    return newSquare;
}

void Square::sort(){
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 3 - j; i++){
            if (points[i].x > points[i+1].x || ((points[i].x == points[i+1].x)&&(points[i].y > points[i+1].y))){
                Point t = points[i];
                points[i] = points[i+1];
                points[i+1] = t;
            }
        }
    }
}

bool Square::isSquare(){
    double side1 = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    double side2 = std::sqrt(std::pow(points[2].x - points[0].x, 2) + std::pow(points[2].y - points[0].y, 2));
    double side3 = std::sqrt(std::pow(points[3].x - points[1].x, 2) + std::pow(points[3].y - points[1].y, 2));
    double side4 = std::sqrt(std::pow(points[2].x - points[3].x, 2) + std::pow(points[2].y - points[3].y, 2));

    if ((side1 != side2) || (side1 != side3) || (side1 != side4)){
        return false;
    }
    return true;
}
