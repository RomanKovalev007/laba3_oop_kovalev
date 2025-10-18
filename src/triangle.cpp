#include "../include/triangle.h"
#include <cmath>

Triangle::Triangle() {
    for (size_t i = 0; i < 3; i++){
        points[i] = Point();
    }
}

Triangle::Triangle(const Point newPoints[3]) {
    for (size_t i = 0; i < 3; i++){
        points[i] = newPoints[i]; 
    }
    if (!isTriangle()) {
        throw std::invalid_argument("it is not a triangle");
    }
    sort();
}

Triangle::Triangle(const Triangle& other){
    for (size_t i = 0; i < 3; i++){
        points[i] = other.points[i];
    }
}

Triangle::Triangle(Triangle&& other) noexcept{
    for (size_t i = 0; i < 3; i++){
        points[i] = std::move(other.points[i]);
    }
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        for (size_t i = 0; i < 3; i++){
            points[i] = other.points[i];
        }
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < 3; i++){
            points[i] = std::move(other.points[i]);
        }
    }
    return *this;
}

bool Triangle::operator==(const Triangle& other) const {
    for (size_t i = 0; i < 3; i++){
        if (points[i].x != other.points[i].x || points[i].y != other.points[i].y){
            return false;
        };
    }
    return true;
}

Point Triangle::gcenter() const {
    double sx = 0, sy = 0;
    for (size_t i = 0; i < 3; i++) {
        sx += points[i].x;
        sy += points[i].y;
    }
    return Point(sx / 3, sy / 3);
}

double Triangle::area() const {
    const Point& p1 = points[0];
    const Point& p2 = points[1];
    const Point& p3 = points[2];
    
    return std::abs(
        0.5 * ((p1.x - p3.x)*(p2.y - p3.y) - (p2.x - p3.x)*(p1.y - p3.y))
    );
}

void Triangle::print(std::ostream& out) const {
    out << "triangle: ";
    for (size_t i = 0; i < 3; i++) {
        out << "(" << points[i].x << ", " << points[i].y << ") ";
    }
}

void Triangle::read(std::istream& in) {
    for (size_t i = 0; i < 3; i++) {
        in >> points[i].x >> points[i].y;
    }
    if (!isTriangle()){
        throw std::invalid_argument("it is not a triangle");
    }
    sort();
}

Triangle *Triangle::clone() const{
    Triangle *newTriangle = new Triangle();
    for (int i = 0; i < 3; ++i){
        newTriangle->points[i] = this->points[i];
    }
    return newTriangle;
}

void Triangle::sort(){
    for (int j = 0; j < 2; j++){
        for (int i = 0; i < 2 - j; i++){
            if (points[i].x > points[i+1].x || ((points[i].x == points[i+1].x)&&(points[i].y > points[i+1].y))){
                Point t = points[i];
                points[i] = points[i+1];
                points[i+1] = t;
            }
        }
    }
}

bool Triangle::isTriangle(){
    double side1 = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    double side2 = std::sqrt(std::pow(points[2].x - points[0].x, 2) + std::pow(points[2].y - points[0].y, 2));
    double side3 = std::sqrt(std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2));

    if ((side1+side2 <= side3) || (side1+side3 <= side2) || (side3+side2 <= side1)){
        return false;
    }
    return true;
}

