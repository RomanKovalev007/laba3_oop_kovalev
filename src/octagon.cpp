#include "../include/octagon.h"
#include <cmath>
#include <vector>
#include <algorithm>

Octagon::Octagon() {
    for (size_t i = 0; i < 8; i++){
        points[i] = Point();
    }
}

Octagon::Octagon(const Point newPoints[8]) {
    for (size_t i = 0; i < 8; i++){
        points[i] = newPoints[i]; 
    }
    sort();
    if (!isOctagon()) {
        throw std::invalid_argument("it is not a octagon");
    }

}

Octagon::Octagon(const Octagon& other){
    for (size_t i = 0; i < 8; i++){
        points[i] = other.points[i];
    }
    
}

Octagon::Octagon(Octagon&& other) noexcept{
    for (size_t i = 0; i < 8; i++){
        points[i] = std::move(other.points[i]);
    }
}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        for (size_t i = 0; i < 8; i++){
            points[i] = other.points[i];
        }
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < 8; i++){
            points[i] = std::move(other.points[i]);
        }
    }
    return *this;
}

bool Octagon::operator==(const Octagon& other) const {
    for (size_t i = 0; i < 8; i++){
        if (points[i].x != other.points[i].x || points[i].y != other.points[i].y){
            return false;
        };
    }
    return true;
}

Point Octagon::gcenter() const {
    double sx = 0, sy = 0;
    for (size_t i = 0; i < 8; i++) {
        sx += points[i].x;
        sy += points[i].y;
    }
    return Point(sx / 8, sy / 8);
}

double Octagon::area() const {
    double area = 0;
    for (size_t i = 0; i < 8; i++) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % 8];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area / 2.0);
}

void Octagon::print(std::ostream& out) const {
    out << "octagon: ";
    for (size_t i = 0; i < 8; i++) {
        out << "(" << points[i].x << ", " << points[i].y << ") ";
    }
}

void Octagon::read(std::istream& in) {
    for (size_t i = 0; i < 8; i++) {
        in >> points[i].x >> points[i].y;
    }
    sort();
    if (!isOctagon()) {
        throw std::invalid_argument("it is not a octagon");
    }
}

Octagon *Octagon::clone() const{
    Octagon *newOctagon = new Octagon();
    for (int i = 0; i < 8; ++i){
        newOctagon->points[i] = this->points[i];
    }
    return newOctagon;
}


void Octagon::sort(){
    Point center = gcenter();
    
    std::sort(points, points + 8, [center](const Point& a, const Point& b) {
        double angleA = std::atan2(a.y - center.y, a.x - center.x);
        double angleB = std::atan2(b.y - center.y, b.x - center.x);
        return angleA < angleB;
    });
}

bool Octagon::isOctagon() {
    for (int i = 0; i < 8; ++i){ 
        Point a = points[i];
        Point b = points[(i+1)%8];
        Point c = points[(i+2)%8];
        
        double side1 = std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
        double side2 = std::sqrt(std::pow(c.x - a.x, 2) + std::pow(c.y - a.y, 2));
        double side3 = std::sqrt(std::pow(c.x - b.x, 2) + std::pow(c.y - b.y, 2));

        if ((side1+side2 <= side3) || (side1+side3 <= side2) || (side3+side2 <= side1)){
            return false;
        }
    }
    return true;

}
